// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
// Example 1:
//
// Input:nums = [1,1,1], k = 2
// Output: 2
//
//
//
// Note:
//
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
//
//
//


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0, len = nums.size();
        unordered_map<int,int> m{{0,1}};   //前缀和的hashmap。要放进一个前缀和为0的次数（前缀和为零，即当前的和已经等于k，无需前缀）
        
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            ans += m[sum-k];  //sum-(sum-k)=k 即加上前缀和为sum-k的次数
            ++m[sum];
        }
        
        return ans;
    }
};
