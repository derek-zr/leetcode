// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //二分法通过比较nums[mid]和nums[right]的大小判断左半段有序还是右半段有序
        //因为这道题会出现相等的情况，所以当两者相等时，考虑不断--right直到不相等
        if (nums.empty()) return false;
        int left = 0, right = nums.size() - 1;
        //二分
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return true;
            else if (nums[mid] > nums[right]) {  //左半段有序
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {   //右半段有序
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
            else --right;   //相等的情况单独考虑
        }
        return false;
    }
};
