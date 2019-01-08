// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        if(rows==0) return 0;
        vector<int> dp[rows];   //n个数组
        dp[0].push_back(triangle[0][0]);
        
        for(int i=1;i<rows;i++){
            for(int j=0;j<=i;j++){
                if(j==0) dp[i].push_back(triangle[i][j]+dp[i-1][j]);
                else if(j==i) dp[i].push_back(triangle[i][j]+dp[i-1][j-1]);
                else dp[i].push_back(triangle[i][j]+min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
        sort(dp[rows-1].begin(),dp[rows-1].end());
        return dp[rows-1][0];
    }
};
