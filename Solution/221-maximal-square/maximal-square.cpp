// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
//
// Input: 
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4
//


class Solution {
public:
    //动态规划
    //dp[i][j]代表到ij位置最大的square的长度
    //dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 if matrix[i][j]==1
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int ans = 0; //记录遍历过程中的最大值，考虑到最后的dp[rows-1][cols-1]可能为零
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++) {dp[i][0] = matrix[i][0]-'0';ans=max(ans,dp[i][0]);}
        for(int j=0;j<cols;j++) {dp[0][j] = matrix[0][j]-'0';ans=max(ans,dp[0][j]);}
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]=='1') {dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                                 ans = max(ans,dp[i][j]); 
                                     }
            }
        }
        
        
        return ans*ans;
    }
};
