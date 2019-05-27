// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
//
//
// Example 2:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
//
//


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //动态规划题。dp[i][j]表示s1的前i个字符和s2的前j个字符组成的长度为i+j的s3
        int len1 = s1.size();
        int len2 = s2.size();
        if(s3.size() != (len1+len2)) return false;  //长度不相等，肯定不可能
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        dp[0][0] = 1;
        //初始化i=0和j=0的情况
        for(int j = 1; j <= len2; ++j) {
            dp[0][j] = (dp[0][j-1] && s2[j-1]==s3[j-1]);
        }
        for(int i = 1; i <= len1; ++i) {
            dp[i][0] = (dp[i-1][0] && s1[i-1]==s3[i-1]);
        } 
        //开始dp
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                //s3当前字符来自s1或s2
                dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        
        return dp[len1][len2];
    }
};
