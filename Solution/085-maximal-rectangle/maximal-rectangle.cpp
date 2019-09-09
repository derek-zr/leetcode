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
    int maximalRectangle(vector<vector<char>>& matrix) {
        //借用最大面积直方图的方法，把各行/列的1的数目当做一个一定高度的直方图
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int ans = 0;
        //统计每一列1的数目(逐步遍历每一行，保证平面是相同的)
        vector<int> heights(matrix[0].size() + 1, 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') heights[j] = 1 + heights[j];
                else heights[j] = 0;
            }
            ans = max(ans, helper(heights));
        }
        return ans;
    }
    
    int helper(vector<int> &heights) {
        stack<int> st;
        //压入0，处理最后一个矩形
        //heights.push_back(0);
        //cout<<heights[0]<<heights[1];
        int ans = 0;
        //递增栈
        for (int i = 0; i < heights.size(); ++i) {
            if (st.empty() || heights[st.top()] < heights[i]) {
                st.push(i);  //压入下标
            }
            else {
                int cur = st.top();
                st.pop();
                //计算最大面积
                //cout<<heights[cur]<<i;
                ans = max(ans, heights[cur]*(st.empty() ? i : i-st.top()-1));
                i--;  //不断计算直到符合递增栈规律
            }
        }
        return ans;
    }
};
