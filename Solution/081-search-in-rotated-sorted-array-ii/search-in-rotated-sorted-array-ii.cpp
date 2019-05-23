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
        //之前的I在做二分法时，通过比较nums[mid]和nums[right]的大小来判断是左半段有序或右半段有序。在这道题中由于存在重复的数，如：[3,1,1],[1,1,3,1]，中间值等于最右边值的时候，3既可以在左边，又可以在右边。对于这种情况，我们--right，把右边的值逐个往左移动，直到不相等。
        int len = nums.size(), left = 0, right = len-1;
        while(left <= right) {
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < nums[right]) {  //右半段有序
                if(nums[mid]<target && nums[right]>=target) left = mid+1;
                else right = mid-1;
            }
            else if(nums[mid] > nums[right]) {  //左半段有序
                if(nums[left]<=target && nums[mid]>target) right = mid-1;
                else left = mid+1;
            }
            else --right;  //相等时，则移动最右边
        }
        return false;
    }
};
