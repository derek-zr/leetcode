// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// Example 2:
//
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//


class Solution {
public:
    int numDistinct(string s, string t) {
        //dp题
        //dp[i][j]表示s的0-(i-1)子串和t的0-(i-1)子串间的distinct seqs数量
        int len1 = s.size(), len2 = t.size();
        //用long long防止溢出
        vector<vector<long long>> dp(len1+1, vector<long long>(len2+1, 0)); 
        dp[0][0] = 1;
        //初始化
        
        //把s删除成空串(t)
        for(int i = 1; i <= len1; ++i) dp[i][0] = 1;
        //s为空串，无法得到非空串t
        //for(int j = 1; j <= len2; ++j) dp[0][j] = 0;
        
        //dp
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                //如果当前位置匹配字符不相等，则跳过（不增加次数）
                if (s[i-1] != t[j-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    //假设相等，也可以选择是否使用当前字符去匹配。
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];     
                }
            }
        }
        return dp[len1][len2];
    }
};
