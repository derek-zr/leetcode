// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        //dp dp[i][j]表示i到j间的子字符串是否为回文
        if(s.empty()) return "";
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int start = 0, ans_len = 1;
        //dp
        for(int i = 0; i < len; ++i) {
            dp[i][i] = 1;   //单个字符一定为回文
            for(int j = 0; j < i; ++j) {
                //i=j+1时满足两个字符相等即可，否则还需要之前的子串为回文
                dp[j][i] = (s[i] == s[j]) && (i-j < 2 || dp[j+1][i-1]);
                if(dp[j][i] && ans_len < i-j+1) {
                    start = j;
                    ans_len = i-j+1;  //记录最长回文串的起始index和长度
                }
            }
        }
        return s.substr(start, ans_len);
    }
};
