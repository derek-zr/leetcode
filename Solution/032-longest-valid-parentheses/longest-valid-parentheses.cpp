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
        //用stack或dp，但dp的递推逻辑比较难想。而stack的逻辑更加直观
        //遇到左括号压栈，遇到右括号出栈。出栈时候根据栈是否为空分情况计算即可。
        int len = s.size();
        int ans = 0, start = 0;
        stack<int> st;  //保存下标，便于计算长度
        
        for(int i = 0; i < len; ++i) {
            if(s[i] == '(') st.push(i);
            else {
                if(st.empty()) start = i+1;  //前面缺少左括号，修改起始位置
                else {
                    st.pop();
                    //弹出后为空，长度根据起始位置计算。弹出后不为空，则根据栈顶元素计算
                    int tmp = st.empty() ? (i-start+1) : (i-st.top());
                    ans = max(ans,tmp);
                }
            }
        }
        
        return ans;
    }
};
