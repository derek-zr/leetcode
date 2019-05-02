// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
public:
    //把这道题转换为前面的largest rect in histogram
    //遍历每一行，如为0则高度为0，如为1则将之前列高度+1
    //对于每一行都调用之前的解法，此时把此题拆分为largest rect in histogram组合成的子问题
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols,0);
        
        int ans = 0;
        for(int i = 0; i < rows; ++i) {
            heights.resize(cols);
            for(int j = 0; j < cols; ++j) {
                if(matrix[i][j]=='0') heights[j] = 0;
                else heights[j] += 1;
            }
            
            ans = max(ans,LargestRectInHist(heights));
        }
        
        return ans;
    }
    
    //largest rect in histogram的问题类型可以归为单调栈
    //在这里使用递增栈，大于的高度入列，小于则弹出计算面积
    int LargestRectInHist(vector<int>& heights) {
        heights.push_back(0);  //使得最后一个矩形都能出栈
        int len = heights.size();
        stack<int> s;
        int ans = 0;
        int i = 0;
        while(i < len) {
            while(!s.empty() && heights[i] <= heights[s.top()]) {  //不停弹出，保证压入元素的高度递增
                int left = s.top();
                s.pop();
                int cur_area = heights[left] * (s.empty() ? i : (i-s.top()-1));
                ans = max(ans,cur_area);  //每次弹出的时候都计算最大值
                cout<<ans;
            }
            s.push(i++);  //压入当前值的下标，便于计算面积
        }
        
        return ans;
    }
};
