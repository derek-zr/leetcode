// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
//
//
// Example 2:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//


class Solution {
public:
    int rob(vector<int>& nums) {
        //动态规划，转换为之前的问题。对于连成圈后的house，对0-len-1, 1-len两段做dp即可（因为第一家和最后一家不能同时抢）
        if (nums.empty()) return 0;
        if (nums.size() == 1)  return nums[0];
        int ans1 = helper(nums, 0, nums.size()-1);
        int ans2 = helper(nums, 1, nums.size());
        return max(ans1, ans2);
    }
    
    int helper(vector<int> &nums, int left, int right) {
        if (right - left == 1)  return nums[left];
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left + 1] = max(nums[left], nums[left + 1]);
        for (int i = left + 2; i < right; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        
        return dp[right-1];
    }
};
