// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
// Find the maximum coins you can collect by bursting the balloons wisely.
//
// Note:
//
//
// 	You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 	0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//
// Example:
//
//
// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);   //在头和尾插入1，即nums[-1]和nums[n]
        int dp[n+2][n+2];        //dp[i][j]:从i到j能得到的max coins
        memset(dp,0,sizeof(dp));
        for(int len=0;len<=n;len++){
            for(int left=1;left+len-1<=n;left++){
                int right=left+len-1;
                for(int j=left;j<=right;j++){
                    dp[left][right]=max(dp[left][right],nums[left-1]*nums[j]*nums[right+1]+dp[left][j-1]+dp[j+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};
