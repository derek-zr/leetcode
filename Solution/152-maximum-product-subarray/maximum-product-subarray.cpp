// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//


class Solution {
public:
    //dp
    //f(i)表示从0到i位置包含nums[i]的最大值，g(i)表示从0到i位置包含nums[i]的最小值
    //每次比较f(i-1)*nums[i] g(i-1)*nums[i]  nums[i]三者中的最大值和最小值，分别更新f和g
    //因为这里存在负数，一旦乘以负数，则会完成从最小到最大的转换
    int maxProduct(vector<int>& nums) {
        int ans = nums[0],max_i = nums[0],min_i = nums[0];
        for(int i=1;i<nums.size();i++){
            int tmp_max=max_i,tmp_min=min_i;
            max_i = max(max(tmp_max*nums[i],tmp_min*nums[i]),nums[i]);
            min_i = min(min(tmp_max*nums[i],tmp_min*nums[i]),nums[i]);
            ans = max(ans,max_i);
        }
        
        return ans;
    }
};
