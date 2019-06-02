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
        //动态规划
        //dp[i][j]表示t[0:i-1]和s[0:j-1]间distinct序列的数目
        int len1 = t.size();
        int len2 = s.size();
        //用long防止大用例时溢出
        vector<vector<long>> dp(len1+1,vector<long>(len2+1,0));
        //初始化
        for(int i = 0; i < len2; ++i) dp[0][i] = 1;  //空串
        for(int i = 1; i < len1; ++i) dp[i][0] = 0;  //空串S的子串不可能等于T
        
        //开始dp
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                //不相等的话，说明匹配完s[j-1]后数目不变化
                if(t[i-1] != s[j-1]) dp[i][j] = dp[i][j-1];
                //相等的话，存在两种情况：第一种不使用当前相等的字符去作为子串即[i][j-1],第二种是使用当前相等的字符去匹配T的最后一个字符
                else dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
        
        return dp[len1][len2];
    }
};
