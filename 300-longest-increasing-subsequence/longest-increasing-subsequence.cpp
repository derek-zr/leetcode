// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        if(nums.size()==0||nums.size()==1) return nums.size();
        tails.push_back(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(nums[i]<tails[0]) tails[0]=nums[i];
            else if(nums[i]>tails.back()) tails.push_back(nums[i]);
            else{
                int left=0,right=tails.size();
                while(left<right){
                    int mid = left+(right-left)/2;
                    if(tails[mid]<nums[i]) left = mid+1;
                    else right=mid;
                }
                tails[right] = nums[i];
            }
        }
        return tails.size();
    }
};
