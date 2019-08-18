// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like . or *.
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
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//
//
// Example 3:
//
//
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
//
// Example 4:
//
//
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
//
//
// Example 5:
//
//
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false
//
//


class Solution {
public:
    bool isMatch(string s, string p) {
        //动态规划，缩减为一维数组
        if(p.empty()) return s.empty();
        int len1 = s.size();
        int len2 = p.size();
        vector<int> dp(len2+1,0);
        
        for(int i=0;i<=len1 ;i++){
            bool pre = dp[0];
            dp[0] = !i;
            for(int j=1;j<=len2; j++){
                bool tmp = dp[j];
                if(j>1 && p[j-1]=='*'){
                    dp[j] = dp[j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[j]);
                }
                else{
                    dp[j] = (i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && pre);
                }
                pre = tmp;
            }
        }
        
        return dp[len2];
        
        /*
        //用动态规划解决
        //dp[i][j] 表示s(0,i) 和 p(0,j)的匹配结果
        if(p.empty()) return s.empty();
        int len1 = s.size();
        int len2 = p.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        dp[0][0] = 1;
        
        for(int i=0;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(j>1 && p[j-1]=='*'){
                    //为0则直接跳过p中的前两个字符（i，j-2）,否则为(i-1,j),p不移动位置
                    dp[i][j] = dp[i][j-2] || (i>0 && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = (i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1]);
                }
            }
        }
        
        return dp[len1][len2];
        */
        /*
        if(p.empty()) return s.empty();
        if(p.size() > 1 && p[1]=='*'){
            //为0则直接跳过p中的前两个字符，否则递归匹配s中的字符
            return isMatch(s,p.substr(2)) || (!s.empty() && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p));
        }
        else{
            return (!s.empty() && (s[0]==p[0] || p[0]=='.') && isMatch(s.substr(1),p.substr(1)));
        }
        */
    }
};
