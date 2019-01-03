//
// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
//
//
// Find out how many ways to assign symbols to make sum of integers equal to target S.  
//
//
// Example 1:
//
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
//
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
//
// There are 5 ways to assign symbols to make the sum of nums be target 3.
//
//
//
// Note:
//
// The length of the given array is positive and will not exceed 20. 
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.
//
//


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //dp数组，其中dp[i][j]表示到第i-1个数字且和为j的情况总数
        unordered_map<int,int> dp;
        dp[0] = 1;
        for(int num : nums){
            unordered_map<int,int> tmp;
            for(auto p : dp){
                int cur_sum = p.first;
                int cur_ways = p.second;
                tmp[cur_sum+num] += cur_ways;
                tmp[cur_sum-num] += cur_ways;
            }
            dp = tmp;
        }
        
        return dp[S];
        
        /*
        int ways = 0;
        int start =0;
        dfs(nums,S,start,ways);
        return ways;
        */
    }
    
    void dfs(vector<int>& nums,int target, int start,int& ways){
        if(target==0 && start==nums.size()) {ways++;return;}
        if(start >= nums.size()) return;
        dfs(nums,target+nums[start],start+1,ways);
        dfs(nums,target-nums[start],start+1,ways);
        return;
    }
    
};
