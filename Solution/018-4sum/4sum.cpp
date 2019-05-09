// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //4sum和之前的方法相同，用两个pointer即可解决
        int len = nums.size();
        vector<vector<int>> ans;
        if(len<4) return ans;
        sort(nums.begin(),nums.end()); //先sort
        for(int i = 0; i < len-3; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < len-2; ++j) {
                if(j> i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1,right=len-1;
                int tmp_target = target-nums[i]-nums[j];
                while(left<right){
                    if(tmp_target==(nums[left]+nums[right])) {
                        vector<int> tmp{nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(tmp);
                        //过滤掉相同的结果
                        while(left<right && nums[left]==nums[left+1]) ++left;
                        while(left<right && nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                    else if((nums[left]+nums[right]) < tmp_target) ++left;
                    else --right;
                }
            }
        }
        return ans;
    }
};
