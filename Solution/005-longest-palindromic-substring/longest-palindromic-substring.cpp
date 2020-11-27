// Given a string s, return the longest palindromic substring in s.
//
//  
// Example 1:
//
//
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: s = "cbbd"
// Output: "bb"
//
//
// Example 3:
//
//
// Input: s = "a"
// Output: "a"
//
//
// Example 4:
//
//
// Input: s = "ac"
// Output: "a"
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 1000
// 	s consist of only digits and English letters (lower-case and/or upper-case),
//
//


class Solution {
public:
    string longestPalindrome(string s) {
        // 尝试所有可能的中心位置
        if (s.empty()) return "";
        int maxStart = 0, maxLen = 1;
        for (int i = 0; i < s.size(); ++i) {
            // 以i字符为中心，或者以i-i+1字符中间的空为中心
            int lenI = getAroundLen(s, i, i);
            int lenE = getAroundLen(s, i, i+1);
            int len = max(lenI, lenE);
            if (len > maxLen) {
                maxLen = len;
                maxStart = i - (len-1) / 2;
            }
        }
        return s.substr(maxStart, maxLen);
        
        /* // dp辅助数组
        if (s.empty()) return "";
        int len = s.size();
        // dp[i][j]表示i到j的子串为回文
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int maxStart = 0, maxLen = 1;
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;  // 单个字符初始化
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[i] == s[j]) && (i - j < 2 || dp[j+1][i-1]);
                if (dp[j][i] && i-j+1 > maxLen) {
                    maxStart = j;
                    maxLen = i-j+1;
                } 
            }
        }
        return s.substr(maxStart, maxLen);
        */
    }
    
    int getAroundLen(string &s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L;
            ++R;
        }
        return R - L - 1;
    }
};
