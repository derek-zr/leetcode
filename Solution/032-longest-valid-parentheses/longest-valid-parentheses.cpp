// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
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
    }
};
