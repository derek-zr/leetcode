// Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]
//
//


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //将i位置的数与nums[i]-1位置的数互换，遍历重复此过程。最后判断nums[i]是否等于i+1
        vector<int> ans;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(nums[i] != nums[nums[i]-1]) {
                swap(nums[i],nums[nums[i]-1]);
                --i;  //这里要减一下，因为换到i位置上的数可能再继续换
            }
        }
        
        for(int i = 0; i < len; ++i) {
            if(nums[i] != i+1) ans.push_back(i+1);
        }
        
        return ans;
    }
};
