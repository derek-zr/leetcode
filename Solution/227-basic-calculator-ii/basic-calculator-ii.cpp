// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: "3+2*2"
// Output: 7
//
//
// Example 2:
//
//
// Input: " 3/2 "
// Output: 1
//
// Example 3:
//
//
// Input: " 3+5 / 2 "
// Output: 5
//
//
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
        //因为存在乘除法，在运算时候需要考虑优先级，则先压栈，再根据相应的运算符计算
        long ans = 0, num = 0, len = s.size();
        char preOp = '+';   //上一个遍历到的运算符,第一个数字进栈
        stack<int> st;     //保存数字和中间计算结果
        
        for (int i = 0; i < len; ++i) {
            while (i < len && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
            }
            //出现了新的运算符
            if ((s[i] < '0' && s[i] != ' ') || i == len-1) {
                if (preOp == '+')  st.push(num);
                else if (preOp == '-')  st.push(-num);
                else if (preOp == '*' || preOp == '/') {
                    int tmp = (preOp == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                preOp = s[i];
                num = 0;
            }
        }
        //计算栈内仍存在的元素
        while (! st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
        /*
        long ans = 0, num = 0, len = s.size();
        char op = '+';  //第一个数字相当于0+num
        stack<int> res;
        
        for(int i =0; i < len; ++i) {
            if(s[i] >= '0' && s[i] <= '9') {
                num = num*10 + s[i]-'0';
            }
            
            if((s[i] < '0' && s[i] != ' ') || i == len-1) {
                if(op == '+') res.push(num);
                if(op == '-') res.push(-num);
                if(op == '*' || op == '/') {
                    int tmp = (op=='*')? res.top()*num : res.top()/num;
                    res.pop();
                    res.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while(!res.empty()) {
            ans += res.top();
            res.pop();
        }
        
        return ans;
        */
    }
};
