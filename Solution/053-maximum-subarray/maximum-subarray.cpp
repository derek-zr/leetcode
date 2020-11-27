// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//
//  
// Example 1:
//
//
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Example 2:
//
//
// Input: nums = [1]
// Output: 1
//
//
// Example 3:
//
//
// Input: nums = [0]
// Output: 0
//
//
// Example 4:
//
//
// Input: nums = [-1]
// Output: -1
//
//
// Example 5:
//
//
// Input: nums = [-2147483647]
// Output: -2147483647
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 2 * 104
// 	-231 <= nums[i] <= 231 - 1
//
//


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //另一种方法是分治法：分别找左右两边数组的最大子数组之和，同时从中间向左右扫描求出最大值并进行比较
        
        int ans  = INT_MIN, curSum = 0;
        for(int num : nums) {
            curSum = max(curSum + num, num);
            ans = max(ans, curSum);
        }
        return ans;
    }
};
