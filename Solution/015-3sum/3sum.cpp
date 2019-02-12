// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    //sum为0，则必然有正有负。先对数组排序，在进行遍历搜索，便于剪枝。
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.empty()||nums.front()>0||nums.back()<0) return ans;
        
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>0) break; //当fix的数为正数时（后面均为正数，不可能满足条件）
            if(i>0 && nums[i]==nums[i-1]) continue; //去除重复
            int target=0-nums[i];
            int j=i+1,k=len-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&nums[j]==nums[j+1]) ++j;
                    while(j<k&&nums[k]==nums[k-1]) --k; //去除重复
                    ++j;--k;
                }
                else if(nums[j]+nums[k]<target) ++j;
                else --k;
            }
        }
        
        return ans;
    }
};
