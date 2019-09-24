// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
// Note that you cannot sell a stock before you buy one.
//
// Example 1:
//
//
// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
//
//
// Example 2:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //因为最多只能交易一次，所以找到符合顺序的最大差值即可
        //即遍历查找目前能买到的最低价，再计算利润差值
        int len = prices.size();
        int profit = 0;
        int minPrice = INT_MAX;
        for(int i=0;i<len;i++){
            minPrice = min(prices[i],minPrice);
            profit = max(profit,prices[i]-minPrice);
        }
        return profit;
    }
};
