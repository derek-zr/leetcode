// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// The array may contain duplicates.
//
// Example 1:
//
//
// Input: [1,3,5]
// Output: 1
//
// Example 2:
//
//
// Input: [2,2,2,0,1]
// Output: 0
//
// Note:
//
//
// 	This is a follow up problem to Find Minimum in Rotated Sorted Array.
// 	Would allow duplicates affect the run-time complexity? How and why?
//
//


class Solution {
public:
    int findMin(vector<int>& nums) {
        //当数组中出现大量重复时候，二分查找就会失效。eg. [2,2,2,0,1,2,2] nums[left]==nums[mid]==nums[right]，没办法继续二分。
        //因此在153二分解法的基础上加上对相等情况的处理，当nums[mid]==nums[right]时候，移动右指针，直到满足其他条件。因此在数组全部相等时，使用二分法的复杂度会退化为O(n)
        int left = 0, right = nums.size()-1;
        if(nums[left] < nums[right]) return nums[0]; //说明数组有序
        
        while(left < right) {
            int mid = left + (right-left)/2;
            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]) return nums[mid+1];   //返回拐点
            else if(nums[mid] > nums[right]) left = mid+1;
            else if(nums[mid] < nums[right]) right = mid;
            else --right;  //新添加的，相等时则移动右指针
        }
        return nums[0];
    }
};
