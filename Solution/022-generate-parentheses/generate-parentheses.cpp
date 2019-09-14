//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //dfs题。但难点在于需要一个符合规则的括号序列，因此我们需要左括号和右括号的匹配
        //为了保证左括号先插入，我们设置两个值left right，将left置为n，将right置为0.dfs过程中，只有大于0才插入
        vector<string> ans;
        string tmp = "";
        helper(ans,tmp,n,0);
        return ans;
    }
    
    void helper(vector<string> &ans, string tmp, int left_cnt, int right_cnt) {
        if(left_cnt == 0 && right_cnt ==0) {
            ans.push_back(tmp);
            return;
        }
        if(left_cnt > 0) helper(ans, tmp+"(", left_cnt-1, right_cnt+1);
        if(right_cnt > 0) helper(ans, tmp+")", left_cnt, right_cnt-1);
    }
};
