// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
//


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
           int len = ans.size();
           for(int j=0;j<len;j++){
               ans.push_back(ans[j]);
               ans.back().push_back(nums[i]);
           }
        }
        
        return ans;
    }
};
