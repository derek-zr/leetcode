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
        //最终都转换为双指针解决的2Sum问题
        vector<vector<int> > ans;
        int len = nums.size();
        if(len < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int a = 0; a  < len-3; ++a) {
            //去除重复
            if(a > 0 && nums[a] == nums[a-1]) continue;
            int target_a = target-nums[a];
            for(int b = a+1; b < len-2; ++b) {
                if(b > a+1 && nums[b] == nums[b-1]) continue;
                int target_b = target_a - nums[b];
                int left = b+1, right = len-1;
                while(left < right) {
                    //cout<<nums[a]<<nums[b]<<nums[left]<<nums[right]<<endl;
                    if(nums[left] + nums[right] == target_b) {
                        ans.push_back({nums[a],nums[b],nums[left],nums[right]});
                        //去除重复
                        while(left < right && nums[left]==nums[left+1]) ++left;
                        while(left < right && nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    }
                    else if(nums[left] + nums[right] < target_b) ++left;
                    else --right;
                }
            }
        }
        return ans;
    }
};
