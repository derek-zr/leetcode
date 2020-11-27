// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//
//  
// Example 1:
//
//
// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
//
//
// Example 2:
//
//
// Input: n = 1
// Output: [[1]]
//
//
//  
// Constraints:
//
//
// 	1 <= n <= 20
//
//


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n,vector<int>(n,0));
        if(n==0) return ans;
        
        //遍历过程中的边界
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        int cur = 0;
        
        //开始遍历
        while(left <= right && top <= bottom) {
            //向右
            for(int i = left; i <= right; ++i) {
                ans[top][i] = ++cur;
            }
            ++top;
            //向下
            for(int i = top; i <= bottom; ++i) {
                ans[i][right] = ++cur;
            }
            --right;
            //向左
            for(int i = right; i >= left; --i) {
                ans[bottom][i] = ++cur;
            }
            --bottom;
            //向上
            for(int i = bottom; i >= top; --i) {
                ans[i][left] = ++cur;
            }
            ++left;
        }
        
        return ans;
    }
};
