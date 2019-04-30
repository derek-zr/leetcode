// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());  //先排一个序
        dfs(ans,candidates,target,0,tmp);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans,vector<int>& candidates, int target, int start, vector<int>& cur) {
        if(target < 0) return;
        if(target == 0) {ans.push_back(cur);return;}
        int len = candidates.size();
        for(int i = start; i < len; ++i) {
            if(target-candidates[i] < 0) break; //如果当前的值已经不满足条件了，则后续的更大的值也没有必要遍历。这里做了剪枝
            cur.push_back(candidates[i]);
            dfs(ans,candidates,target-candidates[i],i,cur);
            cur.pop_back();
        }
    }
};
