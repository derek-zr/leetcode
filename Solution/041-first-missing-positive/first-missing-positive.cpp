// Given an unsorted integer array nums, find the smallest missing positive integer.
//
// Follow up: Could you implement an algorithm that runs in O(n) time and uses constant extra space.?
//
//  
// Example 1:
// Input: nums = [1,2,0]
// Output: 3
// Example 2:
// Input: nums = [3,4,-1,1]
// Output: 2
// Example 3:
// Input: nums = [7,8,9,11,12]
// Output: 1
//
//  
// Constraints:
//
//
// 	0 <= nums.length <= 300
// 	-231 <= nums[i] <= 231 - 1
//
//


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        //nums[i]放在nums[i]-1的位置上，负数和大于len的数直接跳过
        for(int i=0;i<len;i++){
            while(nums[i]>0 && nums[i]<=len && nums[i]!=nums[nums[i]-1]){  //这里必须用while，保证交换后位置也满足条件
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        
        //遍历数组，不满足条件的即为结果
        for(int i=0;i<len;i++){
            if(nums[i]!=i+1) return i+1;
        }
        
        return len+1;
    }
};
