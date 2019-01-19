// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        if(nums.size()==0) return ans;
        int left = 0;
        int right = nums.size()-1;
        int mid=0;
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]<target) left = mid+1;
            else right = mid;
        }
        if(nums[right]!=target) return ans;
        ans[0]=right;
        //do again
        left=0;
        right=nums.size();
        while(left<right){
            mid = left + (right-left)/2;
            if(nums[mid]<=target) left = mid+1;   //修改这里的条件，加上等号
            else right = mid;
        }
        ans[1]=left-1;
        
        return ans;
    }
};
