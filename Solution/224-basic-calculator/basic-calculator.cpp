// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// Example 1:
//
//
// Input: "1 + 1"
// Output: 2
//
//
// Example 2:
//
//
// Input: " 2-1 + 2 "
// Output: 3
//
// Example 3:
//
//
// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:
//
//
// 	You may assume that the given expression is always valid.
// 	Do not use the eval built-in library function.
//
//


class Solution {
public:
    int calculate(string s) {
        //用栈，题目不涉及运算符优先级，所以很简单
        int res = 0, sign = 1, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i < n && s[i] >= '0') {
                    num = 10 * num + (s[i++] - '0');
                }
                res += sign * num;
                --i;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};
