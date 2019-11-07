//
// Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects. 
//
//
//
// You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
//
//
//
// To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.
//
//
// Example 1:
//
// Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
//
// Output: 4
//
// Explanation: Since your initial capital is 0, you can only start the project indexed 0.
//              After finishing it you will obtain profit 1 and your capital becomes 1.
//              With capital 1, you can either start the project indexed 1 or the project indexed 2.
//              Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
//              Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
//
//
//
// Note:
//
// You may assume all numbers in the input are non-negative integers.
// The length of Profits array and Capital array will not exceed 50,000.
// The answer is guaranteed to fit in a 32-bit signed integer.
//
//


class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        //用两个优先队列，一个按照capital从小到大排序，一个按照profit从大到小排序
        //贪心想法：在保证当前capital足够的情况下，选择能达到的最大profit
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>  minCap;
        priority_queue<pair<int, int>> maxPro;
        
        for (int i = 0; i < Profits.size(); ++i) {
            minCap.push({Capital[i], Profits[i]});
        }
        
        //贪心
        for (int i = 0; i < k; ++i) {
            while (!minCap.empty() && minCap.top().first <= W) {
                auto tmp = minCap.top();
                minCap.pop();
                maxPro.push({tmp.second, tmp.first});
            }
            
            if (maxPro.empty())  break;
            W += maxPro.top().first;
            maxPro.pop();
        }
        
        return W;
    }
};
