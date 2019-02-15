// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
//
// Si % Sj = 0 or Sj % Si = 0.
//
// If there are multiple solutions, return any subset is fine.
//
// Example 1:
//
//
//
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
//
//
//
// Example 2:
//
//
// Input: [1,2,4,8]
// Output: [1,2,4,8]
//
//
//


class Solution {
public:
    //动态规划
    //dp[i]表示到第i个位置的最大子集长度，parent[i]表示第i个位置前一个加入子集的数
    //从后往前遍历，进行dp
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;
        vector<int> dp(len,0),parent(len,0);
        int max_len=0,max_index=0;
        sort(nums.begin(),nums.end());
        
        for(int i=len-1;i>=0;--i){
            for(int j=i;j<len;++j){  //题目没有限制i必须不等于j
                if(nums[j]%nums[i]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
                if(max_len<dp[i]){
                    max_len=dp[i];
                    max_index=i;
                }
            }
        }
        //回溯找到结果数组
        for(int i=0;i<max_len;i++){
            ans.push_back(nums[max_index]);
            max_index=parent[max_index];
        }
        return ans;
        
    }
};
