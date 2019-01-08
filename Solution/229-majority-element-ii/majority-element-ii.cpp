// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
//
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
//
//
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
//
//
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]
//


class Solution {
public:
    //https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> results;
        if(n==0) return results;
        //vote algorithm
        int cnt1=0,cnt2=0;
        int result1=nums[0],result2=nums[0];
        
        for(int num : nums){
            if(num==result1) cnt1++;
            else if(num==result2) cnt2++;
            else if(cnt1==0) {result1=num;cnt1=1;}
            else if(cnt2==0) {result2=num;cnt2=1;}
            else {cnt1--;cnt2--;}
        }
        cnt1=0;
        cnt2=0;
        for(int num:nums){
            if(num==result1) cnt1++;
            else if(num==result2) cnt2++;
        }
        if(cnt1>n/3) results.push_back(result1);
        if(cnt2>n/3) results.push_back(result2);
        return results;
    }
};
