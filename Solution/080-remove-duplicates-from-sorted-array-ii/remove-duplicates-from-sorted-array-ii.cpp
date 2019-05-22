// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// Example 1:
//
//
// Given nums = [1,1,1,2,2,3],
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//
// It doesn't matter what you leave beyond the returned length.
//
// Example 2:
//
//
// Given nums = [0,0,1,1,1,1,2,3,3],
//
// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
//
// It doesn't matter what values are set beyond the returned length.
//
//
// Clarification:
//
// Confused why the returned value is an integer but your answer is an array?
//
// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
// Internally you can think of this:
//
//
// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);
//
// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }
//
//


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return len;
        //这道题允许最多重复两次
        int index = 2; //从2开始遍历即可（不过前两个元素是否相同，我们都会保留他们）
        for(int i = 2; i < len; ++i) {
            //只需要比较i和index-2下标的值即可
            //因为最多允许重复两次，即存在index-2==index-1情况，此时如果index继续等于index-1，那么则不能加入结果中
            if(nums[i] != nums[index-2]) nums[index++] = nums[i];
        }
        return index;
    }
};
