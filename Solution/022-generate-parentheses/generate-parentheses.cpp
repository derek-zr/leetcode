// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//  
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:
// Input: n = 1
// Output: ["()"]
//
//  
// Constraints:
//
//
// 	1 <= n <= 8
//
//


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0) return ans;
        string tmp;
        int left=n,right=0;
        dfs(ans,tmp,left,right);
        return ans;
    }
    
    void dfs(vector<string>& ans,string tmp,int left,int right){
        if(left==0&&right==0){
            ans.push_back(tmp);
            return;
        }
        if(left>0) dfs(ans,tmp+'(',left-1,right+1);
        if(right>0) dfs(ans,tmp+')',left,right-1);
    }
};
