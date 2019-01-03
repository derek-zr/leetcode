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
        int size=nums.size();
        if(size==0) return 0;
        if(size==1) return nums[0];
        int ans1=dpSolve(nums,0,size-1);
        int ans2=dpSolve(nums,1,size);
        return max(ans1,ans2);
    }
    
    int dpSolve(vector<int>& nums,int start,int end)
    {
        vector<int> dp1(end-start,0);  //抢当前这间
        vector<int> dp2(end-start,0);  //不抢当前这间
        dp1[0]=nums[start];
        for(int i=1;i<end-start;i++){
            dp2[i]=max(dp1[i-1],dp2[i-1]);
            dp1[i]=max(dp1[i],dp2[i-1]+nums[i+start]);
        }
        return max(dp1[end-start-1],dp2[end-start-1]);
    }
};
