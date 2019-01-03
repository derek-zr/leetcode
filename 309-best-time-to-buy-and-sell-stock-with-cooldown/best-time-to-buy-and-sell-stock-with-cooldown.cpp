// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
//
// 	You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// 	After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//
//
// Example:
//
//
// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]
//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        vector<int> buy(prices.size(),0);
        vector<int> sell(prices.size(),0);
        vector<int> cooldown(prices.size(),0);
        buy[0]=-prices[0];
        for(int i=1;i<prices.size();i++){
            buy[i]=max(cooldown[i-1]-prices[i],buy[i-1]);
            sell[i]=max(buy[i-1]+prices[i], sell[i-1]);
            cooldown[i]=max(max(buy[i-1],sell[i-1]),cooldown[i-1]);
        }
        return sell[prices.size()-1];
    }
};
