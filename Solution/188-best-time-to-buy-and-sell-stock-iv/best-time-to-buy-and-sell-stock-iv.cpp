// Say you have an array for which the i-th element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//
// Example 2:
//
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//
//


class Solution {
public:
    /*
    动态规划解决：local[i][j]表示前i天最多进行j次交易且最后一天（第i天）进行交易的最大利润
    global[i][j]表示前i天最多进行j次交易的最大利润
    状态转移方程：
    global[i][j]=max(local[i][j],global[i-1][j])
    local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)
    上面式子的第一部分：
    这个是使用前面j-1次交易，然后最后一次交易在倒数第二天买进，然后最后一天卖出.diff>0
    或者最后一天买入并卖出，diff<0.
    第二部分：
    为什么需要一个local最优呢？因为第i天的交易可以和i-1天的交易合并，不需要增加交易次数。这就是为什么要计算一个：local[i-1][j] + diff
    这个就是合并第(i-1)与第i天交易的结果。
    
    最后，当k远大于天数的时候，问题转化为II，可以用贪心算法解决。
    */
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        if(k>prices.size()) return greedyProfit(prices);
        int global[k+1] = {0};
        int local[k+1] = {0};
        for(int i=1;i<prices.size();i++){
            int diff = prices[i]-prices[i-1];
            for(int j=k;j>0;j--){  
                //这里倒序，因为我们用了一维数组。
                //如果正序遍历的话，比如我们在计算[i][j]时需要[i-1][j-1],但在一维数组中，这个位置的值已经被[i][j-1]覆盖
                local[j] = max(global[j-1]+max(diff,0),local[j]+diff);
                global[j] = max(local[j],global[j]);
            }
        }
        
        return global[k];
    }
    
    int greedyProfit(vector<int>& prices){
        int profits=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) profits+=prices[i]-prices[i-1];  //能赚钱就赚
        }
        return profits;
    }
};
