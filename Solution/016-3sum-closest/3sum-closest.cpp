// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
//  
// Example 1:
//
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//
//  
// Constraints:
//
//
// 	3 <= nums.length <= 10^3
// 	-10^3 <= nums[i] <= 10^3
// 	-10^4 <= target <= 10^4
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int closest = nums[0]+nums[1]+nums[2];
        int diff = abs(closest-target);
        int len = nums.size();
        //用双指针
        sort(nums.begin(),nums.end()); //first sort
        for(int i = 0; i < len-2; ++i) {
            int tmp = nums[i];
            if(i > 0 && nums[i]==nums[i-1]) continue;
            int left = i+1,right = len-1;
            while(left < right) {
                int tmp_sum = tmp + nums[left] + nums[right];
                int tmp_diff = abs(tmp_sum-target);
                if(tmp_diff < diff) {
                    diff = tmp_diff;
                    closest = tmp_sum;
                }
                if(tmp_sum<target) ++left;  //小于目标值则找更大的数
                else --right;
            }
        }
        
        return closest;
    }
};
