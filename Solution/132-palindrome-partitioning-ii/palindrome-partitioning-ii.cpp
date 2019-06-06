// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//
//


class Solution {
public:
    int minCut(string s) {
        //动态规划。dp[i]表示前i个字符组成的子串最小切割数
        //状态转移方程为：dp[i] = 1+dp[j] 如果j到i的子串为回文的话（即从j处切一刀满足条件）
        //在判断i到j是否为回文时，可以使用另一个dp数组，减少每次都check回文的计算量
        if(s.empty()) return 0;
        int len = s.size();
        vector<int> dp(len);
        vector<vector<int>> par(len,vector<int>(len,0));
        
        for(int i = 0; i < len; ++i) {
            dp[i] = i;  //前i个子串可以分割成一个个的字符
            for(int j = 0; j <= i; ++j) {
                if(s[i] == s[j] && (i-j < 2 || par[j+1][i-1])) {
                    par[j][i] = 1;
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len-1];
    }
};
