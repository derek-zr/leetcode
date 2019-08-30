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
    bool isMatch(string s, string p) {
        //可以递归匹配，也可以用dp递推公式计算
        //dp[i][j]表示s前i个字符和p前j个字符是否匹配
        int s_len = s.size(), p_len = p.size();
        vector<vector<int>> dp(s_len+1, vector<int>(p_len+1,0));
        dp[0][0] = 1;
        //s如果为空串的情况，根据p中*的情况判断是否符合
        for(int j = 1; j <= p_len; ++j) {
            if(p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }
        //dp
        for(int i = 1; i <= s_len; ++i) {
            for(int j = 1; j <= p_len; ++j) {
                if(p[j-1] == '*') {
                    //匹配空字符或只匹配一个字符
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];  
                }
                else {
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                }
            }
        }
        return dp[s_len][p_len];
    }
};
