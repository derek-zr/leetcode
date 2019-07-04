// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
// Example 1:
//
//
// Input: "2-1-1"
// Output: [0, 2]
// Explanation: 
// ((2-1)-1) = 0 
// (2-(1-1)) = 2
//
// Example 2:
//
//
// Input: "2*3-4*5"
// Output: [-34, -14, -10, -10, 10]
// Explanation: 
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
//


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //用分治法做。当找到一个操作符op后，我们递归地去找其左边字符串可能的取值数组，右边字符串可能的取值数组
        //那么现在我们可以用()op()计算所有新的可能的值
        vector<int> ans;
        int len = input.size();
        for(int i = 0; i < len; ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                int len_left = left.size(), len_right = right.size();
                for(int j = 0; j < len_left; ++j) {
                    for(int k = 0; k < len_right; ++k) {
                        if (input[i] == '+') ans.push_back(left[j] + right[k]);
                        else if (input[i] == '-') ans.push_back(left[j] - right[k]);
                        else ans.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(input));
        return ans;
    }
};
