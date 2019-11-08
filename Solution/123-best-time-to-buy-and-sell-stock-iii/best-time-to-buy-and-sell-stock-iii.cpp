// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
//
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
//
//
// Example 3:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //这里用一个统一的框架解决这个问题dp[i][k][0/1]表示在i天做了至多k次交易，手上持有0/1股票的最大利润
        //那么根据状态转移方程，就可以写出各种情况下的状态转移方程。在本题中k=2,建立这样一个数组即可
        const int days = prices.size();
        if (days == 0)  return 0;
        int dp[days][3][2] = {0};
        //dp
        for (int i = 0; i < days; ++i) {
            for (int k = 1; k < 3; ++k) {
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];   //处理第一天的情况
                    continue;
                }
                //继续不买或者卖出之前买进的股票
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                //继续不卖或者买入当天的股票
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }
        
        //最大利润一定是最后一天没有股票库存的情况
        return dp[days-1][2][0];
        
        /*
        //动态规划。dp[i][j]表示前i天最多j次交易的最大利润
        //但这里dp存在两种情况：local[i][j]表示第i天一定卖出，global[i][j]则不一定
        //最后找到的global[len-1][2]即为最大利润
        if(prices.empty()) return 0;
        int len = prices.size();
        int k = 3;  //最多交易两次
        vector<vector<int>> local(len,vector<int>(k,0));
        vector<vector<int>> global(len,vector<int>(k,0));
        
        for(int i = 1; i < len; ++i) {
            int diff = prices[i]-prices[i-1];
            for(int j = 1; j <= 2; ++j) {
                //第i天卖出：一种情况时根据全局在i-1天内j-1次交易的最大值再加上diff,或者local[i-1][j]+diff(把i-1天卖出的股票改为i天卖出)
                //global[i-1][j-1]+max(diff,0)意思是如果第i天的diff小于0，那么交易就变成第i天买，第i天卖，也就是0，否则就亏了。后者local[i-1][j]已经有了j次交易，但是local[i][j]要求交易必须发生在当前天，所以diff无论大于0还是小于0都要加，也就是说把第i-1天的卖出改为第i天卖出，不管你是不是赚了
                local[i][j] = max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff);
                global[i][j] = max(global[i-1][j],local[i][j]);
            }
        }
        return global[len-1][2];
        */
    }
};
