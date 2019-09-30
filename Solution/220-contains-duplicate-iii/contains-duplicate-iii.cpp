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


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //维持一个k的滑动窗口（保证坐标相差为k以内），同时用set这种自带排序的数据结构，找相差为t的下边界
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)  s.erase(nums[i - k - 1]);
            //找第一个大于等于nums[i]-t的下标
            auto index = s.lower_bound((long long)nums[i] - t);
            if (index != s.end() && abs(*index - nums[i] <= t))  return true;
            s.insert(nums[i]);
        }
        return false;
        /*
        set<long> m;  //这里需要用long，因为INT_MAX-(-INT_MAX) 超过了int范围
        for(int i=0;i<nums.size();i++){
            if(i>k) m.erase(nums[i-k-1]);
            //|nums[i]-nums[j]|<=t  ==>>  -t<=nums[i]-nums[j]<=t
            auto index = m.lower_bound((long long)nums[i]-t);
            if(index!=m.end() && abs(*index-nums[i])<=t) return true;
            m.insert(nums[i]);
        }
        return false;
        */
    }
};
