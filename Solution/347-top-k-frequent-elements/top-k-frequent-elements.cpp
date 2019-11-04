// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
//
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
//
//
// Example 2:
//
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
// Note: 
//
//
// 	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// 	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
//


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //先建立一个hashmap
        unordered_map<int,int> m;
        for(int num : nums) ++m[num];
        
        //再将次数和对应的数放进一个最大堆中
        //或者使用桶排序，按照出现次数将数字放到对应位置
        priority_queue<pair<int,int>> h;
        for(auto p : m) {
            h.push({-p.second,p.first}); //压入次数的负值，相当于最小堆
            if(h.size() > k) h.pop();  //弹出最大值（即次数的最小值）
        }
        
        //生成结果
        vector<int> ans(k);
        for(int i = k-1; i >= 0; --i) {
            ans[i] = h.top().second;
            h.pop();
        }
        
        return ans;
    }
};
