// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note: You are not suppose to use the library's sort function for this problem.
//
// Example:
//
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
// Follow up:
//
//
// 	A rather straight forward solution is a two-pass algorithm using counting sort.
// 	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// 	Could you come up with a one-pass algorithm using only constant space?
//
//


class Solution {
public:
    //双指针
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        for(int i=0;i<=right;i++){
            if(nums[i]==0) swap(nums[i],nums[left++]);
            if(nums[i]==2) swap(nums[i--],nums[right--]);   //这里i仍需要--，使得i留在原地。因为可能还需要继续交换。
            //eg. [1,2,0] 如果不用i--，会得到[1,0,2]的错误答案
        }
        
        return;
    }
};
