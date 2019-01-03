// There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
//
//  
//
// Example 1:
//
//
// Input: m = 2, n = 2, N = 2, i = 0, j = 0
// Output: 6
// Explanation:
//
//
//
// Example 2:
//
//
// Input: m = 1, n = 3, N = 3, i = 0, j = 1
// Output: 12
// Explanation:
//
//
//
//  
//
// Note:
//
//
// 	Once you move the ball out of boundary, you cannot move it back.
// 	The length and height of the grid is in range [1,50].
// 	N is in range [0,50].
//
//


class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long dp[51][51][51]={}; //Ntimes,i,jcoordinate 这里用long，否则会溢出，导致结果错误
        for(int i=1;i<=N;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    dp[i][j][k] = ((j==0 ? 1 : dp[i-1][j-1][k]) + (j==m-1 ? 1 : dp[i-1][j+1][k]) + (k==0 ? 1 : dp[i-1][j][k-1]) + (k==n-1 ? 1 : dp[i-1][j][k+1])) % 1000000007;
                }
            }
        }
        
        return dp[N][i][j];
    }
};
