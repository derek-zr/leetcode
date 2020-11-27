// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// If target is not found in the array, return [-1, -1].
//
// Follow up: Could you write an algorithm with O(log n) runtime complexity?
//
//  
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
//
//  
// Constraints:
//
//
// 	0 <= nums.length <= 105
// 	-109 <= nums[i] <= 109
// 	nums is a non-decreasing array.
// 	-109 <= target <= 109
//
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //二分法，查找第一个等于和最后一个等于的下标
        vector<int> ans(2, -1);
        if(nums.empty())  return ans;
        
        //第一次二分查找左边界
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (right == nums.size() || nums[right] != target) return ans;
        ans[0] = right;
        
        //第二次二分查找小于target+1的值下标
        //这里left不需要再初始化为0了，因为我们现在找的是右边界，所以在之前left的右半段查找即可,加速
        left = 0;  //加或不加都可以AC
        right = nums.size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        //cout<<right<<nums[right];
        ans[1] = right-1;
        
        return ans;
    }
};
