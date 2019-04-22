// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
// Example 1:
//
//
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
//
//
// Example 2:
//
//
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//
//


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //dfs+dp  dp用于memorization,剪枝
        if(matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                ans = max(ans,dfs(matrix,dp,i,j));
            }
        }
        
        return ans;
    }
    
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int i,int j) {
        if(dp[i][j]) return dp[i][j];  //剪枝
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int cur_max = 1;
        
        for(auto dir : dirs) {
            int tmpX = i + dir[0];
            int tmpY = j + dir[1];
            if(tmpX < 0 || tmpX >= matrix.size() || tmpY < 0 || tmpY >= matrix[0].size() || matrix[tmpX][tmpY] <= matrix[i][j]) continue;
            cur_max = max(cur_max, 1+dfs(matrix,dp,tmpX,tmpY));
        }
        dp[i][j] = cur_max;
        return cur_max;
    }
};
