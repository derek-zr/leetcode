// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
//
//
// Example 1:
//
//
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
//
//
//
// Example 2:
//
//
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
//
//
//
// Example 3:
//
//
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
//
//
//
//
//


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long,int> m;  //这里需要用longlong，因为INT_MAX-(-INT_MAX) 超过了int范围
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(i-j>k) m.erase(nums[j++]);
            //|nums[i]-nums[j]|<=t  ==>>  -t<=nums[i]-nums[j]<=t
            auto index = m.lower_bound((long long)nums[i]-t);
            if(index!=m.end() && abs(index->first-nums[i])<=t) return true;
            m[nums[i]]=i;
        }
        return false;
    }
};
