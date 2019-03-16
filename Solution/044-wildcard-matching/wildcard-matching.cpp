// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
//
// Example 1:
//
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
//
// Example 2:
//
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
//
// Example 3:
//
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
//
// Example 4:
//
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
//
// Example 5:
//
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false
//
//


class Solution {
public:
    //用动态规划解决
    bool isMatch(string s, string p) {
        int len1 = s.size(), len2 = p.size();
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
        //dp表示s的i位置前字符串和p的j位置前字符串是否匹配
        dp[0][0] = true;
        for(int i=1;i<=len2;i++){
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];  //星号可以匹配空字符串
        }
        
        //开始dp
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];  //星号可以匹配空字符串，也可以匹配n个字符
                }
                else {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1]==s[i-1] || p[j-1]=='?');
                }
            }
        }
        
        
        return dp[len1][len2];
    }
};
