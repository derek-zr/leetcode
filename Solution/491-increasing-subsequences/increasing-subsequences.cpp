// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2.
//
//  
//
// Example:
//
//
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
//
//
//  
//
// Note:
//
//
// 	The length of the given array will not exceed 15.
// 	The range of integer in the given array is [-100,100].
// 	The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
//
//


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //dfs+hashset去除重复
        vector<vector<int>> ans;
        vector<int> tmp;
        helper(nums, ans, tmp, 0);
        return ans;
    }
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>&tmp, int start) {
        if (tmp.size() >= 2) {
            ans.push_back(tmp);
        }
        unordered_set<int> st;
        for (int i = start; i < nums.size(); ++i) {
            if ((!tmp.empty() && tmp.back() > nums[i]) || st.count(nums[i]))  continue;
            tmp.push_back(nums[i]);
            st.insert(nums[i]);
            helper(nums, ans, tmp, i+1);
            tmp.pop_back();
        }
    }
};
