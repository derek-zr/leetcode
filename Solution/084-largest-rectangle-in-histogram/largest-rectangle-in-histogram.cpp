// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//  
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
    //单调栈，这道题用递增栈。因为矩形面积取决于最短的一块板
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s; //栈内压的是下标，方便计算矩形宽度
        heights.push_back(0);  //最后压入一个0，使得最后一个矩形块也能被处理
        int i = 0;
        int len = heights.size();
        int ans = 0;
        
        while(i<len) {
            while(!s.empty() && heights[i]<=heights[s.top()]){
                int left = s.top();
                s.pop();
                //i - 1 - s.top() uses the starting index where height[s.top() + 1] >= height[tp], because the index on top of the stack right now is the first index left of tp with height smaller than tp's height
                ans = max(ans,heights[left]* (s.empty()? i : (i-s.top()-1)));
            }
            s.push(i++);
        }
        
        return ans;
    }
};
