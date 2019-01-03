// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
//
//  
//
// Example 1:
//
//
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//
//
//  
//
// Note:
//
//
// 	1 <= k <= len(nums) <= 16.
// 	0 < nums[i] < 10000.
//
//


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int num:nums) sum+=num;
        if(k<=0 || sum%k!=0) return false;
        vector<bool> visited(nums.size(),false);
        sort(nums.begin(),nums.end());
        return dfs(nums,k,sum/k,visited,0,0,0);   //cur_num in case target=0
    }
    
    bool dfs(vector<int>& nums,int k,int target,vector<bool>& visited,int start,int cur_sum,int cur_num){
        if(k==1) return true;
        if(cur_sum==target && cur_num>0) return dfs(nums,k-1,target,visited,0,0,0);  //已经找到一组，再寻找新的
        if(cur_sum > target) return false;   //剪枝
        for(int i=start;i<nums.size();i++){
            if(!visited[i]){
                visited[i] = true;
                if(dfs(nums,k,target,visited,i,cur_sum+nums[i],cur_num++)) return true;
                visited[i] = false;
            }
        }
        
        return false;
    }
};
