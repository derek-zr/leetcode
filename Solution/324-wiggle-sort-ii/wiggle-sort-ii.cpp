// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
// Example 1:
//
//
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].
//
// Example 2:
//
//
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].
//
// Note:
// You may assume all input has valid answer.
//
// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int len = nums.size();
        int mid = (len+1)/2;
        int left = mid-1, right = len-1;
        sort(tmp.begin(),tmp.end());
        //按照奇偶位数，分别从左右半部的末端取相应的数
        //这里从末端取的原因是为了把可能相等的错开
        //否则对于4554这样的情况，从头部取得到的依然是4554
        for(int i = 0; i < len; ++i) {
            nums[i] = (i & 1) ? tmp[right--] : tmp[left--];
        }
    }
};
