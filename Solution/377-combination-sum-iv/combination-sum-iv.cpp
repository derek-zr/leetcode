// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//  
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers?
//
// Credits:
// Special thanks to @pbrother for adding this problem and creating all test cases.
//


/*class Solution {
public:
    int ans=0;
    int combinationSum4(vector<int>& nums, int target) {
        dfs(nums,target);
        return ans;
    }
    
    void dfs(vector<int>& nums, int target)
    {
        if(target==0){ans++;return;}
        if(target<0) return;
        for(int i=0;i<nums.size();i++)
            dfs(nums,target-nums[i]);
        return;
    }
};*/   //TLE

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> dp(target+1,0);
       dp[0]=1;
       for(int i=1;i<=target;i++){
           for(int num:nums){
               if(num<=i) dp[i]+=dp[i-num];
           }
       }
        return dp[target];
    }
};
