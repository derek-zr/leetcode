// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
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
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //dfs题，但是需要去除重复
        vector<vector<int>> ans;
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        helper(ans, target, candidates, cur, 0);
        return ans;
    }
    
    void helper(vector<vector<int>> &ans, int target, vector<int>& candidates, vector<int> &cur, int start) {
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        //dfs
        for (int i = start; i < candidates.size(); ++i) {
            if (target < candidates[i]) break;  //剪枝
            if(i > start && candidates[i] == candidates[i-1]) continue;  //去重
            cur.push_back(candidates[i]);
            helper(ans, target-candidates[i], candidates, cur, i+1);
            cur.pop_back();
        }
        return;
    }
};
