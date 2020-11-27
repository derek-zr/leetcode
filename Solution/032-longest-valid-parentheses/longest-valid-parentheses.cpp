// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//  
// Example 1:
//
//
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
//
//
// Example 2:
//
//
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
//
//
// Example 3:
//
//
// Input: s = ""
// Output: 0
//
//
//  
// Constraints:
//
//
// 	0 <= s.length <= 3 * 104
// 	s[i] is '(', or ')'.
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        //动态规划的方法
        //dp[i]表示以s[i-1]结尾的最长合格括号的长度
        int len = s.size();
        int ans = 0;
        vector<int> dp(len+1, 0);
        for(int i = 1; i <= len; ++i) {
            //s[i] = '('：dp[i] = 0 
            //s[i] = ')'：找i前一个字符的最长括号串DP[i]的前一个字符j = i-2-DP[i-1]
            //DP[i] = DP[i-1] + 2 + DP[j]，如果j >=0，且s[j] = '('
            //DP[i] = 0，如果j<0，或s[j] = ')'
            int j = i-2-dp[i-1];   //注意i对应i-1，则前一个字符为i-2
            if(s[i-1] == '(' || j < 0 || s[j]==')') {
                dp[i] = 0;
            }
            else {
                //s[i-1]=')' && s[j]=='(' 可以配对，长度增加了2
                dp[i] = dp[i-1] + 2 + dp[j];   //再加上dp[j]结尾的最长长度
                ans = max(ans, dp[i]);
            }
        }
        return ans;
        
        /*
        //用栈的思路比较直观
        int len = s.size();
        int ans = 0, start = 0;
        stack<int> st;  //压入的是下标
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') st.push(i);
            else {
                if(st.empty()) start = i+1;  //之前没有(压入，不能匹配
                else {
                    int tmp = st.top();
                    st.pop();
                    //如果为空则说明之前所有的括号都已经匹配，则更新长度为上次的start
                    //如果还有左括号，则说明这个左括号暂时还未匹配，根据栈顶下标计算即可。
                    int tmp_len = st.empty()? i-start+1 : i-st.top();
                    ans = max(ans, tmp_len);
                }
            }
        }
        return ans;
        */
    }
};
