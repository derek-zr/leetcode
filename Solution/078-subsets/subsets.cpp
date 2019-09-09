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
        //每次操作如下：
        //一开始ans压入一个空串，然后对ans中当前压入的所有数组，压入数组，并在尾部添加一个nums[i]即可得到第二步结果，即[][1]
        //以此递推，就能够得到所有的子串
        vector<vector<int>> ans(1);  //存入一个空串
        
        for (int i = 0 ; i < nums.size(); ++i) {
            int len = ans.size();
            for (int j  = 0; j < len; ++j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            } 
        }
        return ans;
    }
};
