// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Example:
//
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
// Follow up:
// Could you solve it in linear time?


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //用deque存储下标，构建一个单调队列的结构
        vector<int> ans;
        deque<int> q;
        int len = nums.size();
        
        for(int i = 0; i < len; ++i) {
            if(!q.empty() && q.front() == i-k) q.pop_front();  //队列头已经不在window内
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();  //弹出队列中小于当前值的下标，维护单调性
            q.push_back(i);
            if(i >= k-1) ans.push_back(nums[q.front()]);    //压入当前windows里的最大值
        }
        
        return ans;
        
    }
};
