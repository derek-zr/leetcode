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
    //dfs
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        if(candidates.size()==0) return ans;
        vector<int> tmp;
        int start = 0;
        dfs(ans,candidates,target,tmp,start);
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans,vector<int>& candidates,int target,vector<int>& tmp,int start){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) return;  //剪枝，这种情况没必要再继续dfs
            if(i && candidates[i]==candidates[i-1]&& i>start) continue; // 去除重复 重要！！！
            tmp.push_back(candidates[i]);
            dfs(ans,candidates,target-candidates[i],tmp,i+1);
            tmp.pop_back();
        }
    }
};
