//
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
// Note:
//
//
// 	All numbers will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: k = 3, n = 7
// Output: [[1,2,4]]
//
//
// Example 2:
//
//
// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k==0) return ans;
        vector<int> tmp;
        dfs(ans,tmp,k,n,1);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans,vector<int>& tmp,int k,int n,int start){
        if(k==0 && n==0) {ans.push_back(tmp);return;}
        if(k==0 && n!=0) return;    //数字已经用完，但和与target不同
        if(n<0) return;             //当前的和已经大于target，无需继续
        
        for(int i=start;i<=9;i++){
            tmp.push_back(i);
            dfs(ans,tmp,k-1,n-i,i+1);
            tmp.pop_back();
        }
        return;
    }
};
