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
        //从后往前找到第一个非降序的数字，再找该数字后面的next大的数字，交换两者位置，
        //再反转其后的数组，即可得到结果。
        int i,j;
        int len = nums.size();
        
        for(i=len-2;i>=0;i--){
            if(nums[i+1] > nums[i]){
                for(j=len-1;j>i;j--){
                    if(nums[j] > nums[i]) break;  //从后往前第一个大的即为next大（为降序排列）
                }
    
                swap(nums[i],nums[j]);
                reverse(nums.begin()+i+1,nums.end());
                return;
            }
        }
        
        reverse(nums.begin(),nums.end()); //考虑如321这种已经完全降序的情况
        return;
    }
};
