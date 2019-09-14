// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.
//
//


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        //优化空间，为一维数组。
        vector<int> dp(cols, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                //处理第一列的情况
                if(j == 0) dp[j] += grid[i][j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
            }
        }
        return dp[cols-1];
        
        /*
        int dp[rows][cols];
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        for(int i=1;i<rows;i++)
            dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int i=1;i<cols;i++)
            dp[0][i]=grid[0][i]+dp[0][i-1];
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[rows-1][cols-1];
        */
    }
};
