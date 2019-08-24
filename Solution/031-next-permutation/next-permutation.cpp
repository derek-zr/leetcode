// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //找到尾部第一个逆序的和它next大的数，交换两者位置
        int len = nums.size();
        for(int i = len-2; i >= 0; --i) {
            int j = i+1;
            if(nums[i] < nums[j]) {  //逆序
                for(j = len-1; j > i; --j) {
                    //找next大的数，从尾部遍历，找到第一个即是
                    if(nums[j] > nums[i]) break;
                }
                //交换
                swap(nums[i], nums[j]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        //全部逆序 321这种情况
        reverse(nums.begin(), nums.end());
        return;
    }
};
