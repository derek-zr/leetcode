// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
//
// Input: [1,2,0]
// Output: 3
//
//
// Example 2:
//
//
// Input: [3,4,-1,1]
// Output: 2
//
//
// Example 3:
//
//
// Input: [7,8,9,11,12]
// Output: 1
//
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.
//


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //核心思想是把nums[i]放在nums[i]-1的下标位置上。即保证最后的数组，i+1位置存放的是i
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            //核心步骤,一定要用while循环，保证交换后的位置也被正确处理
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i]-1] != nums[i]) { //这里不能直接判断下标是否符合条件，因为数组中可能存在相同的值如[1,1]，会死循环
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < len; ++i) {
            if(nums[i] != i+1) return i+1;
        }
        
        return len+1;
    }
};
