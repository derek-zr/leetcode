// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//
//


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //考虑每次新进来的nums[i]，如果它与前一个压入的值不相等，则对当前所有可能子集的后面都压入新值
        //如果与前一个压入的相等，则不需要考虑已经压入上一个数的子集
        sort(nums.begin(),nums.end());  //结果中的数组要求按顺序排列
        vector<vector<int>> ans={{}};    //{{}}此时数组size为1，压入了空集 [[]]
        int start = 0;
        int last = 0;
        for(int i=0;i<nums.size();i++){
            start = i>=1 && nums[i]==nums[i-1] ? last:0;
            last = ans.size();
            for(int j=start;j<last;j++){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
