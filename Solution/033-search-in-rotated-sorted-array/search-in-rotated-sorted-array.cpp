// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        //二分法。难点在于left++和right--的条件寻找
        if (nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        //二分
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //这里和right比较的原因是：mid有可能和left相等，例如对于一个长度为2的数组
            else if (nums[mid] > nums[right]) {   //左半段是有序
                //判断是否在左半段中
                if (nums[left] <= target && nums[mid] > target) right = mid-1;  
                else left = mid + 1;
            }
            else {   //右半段有序
                 //判断是否在右半段
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};
