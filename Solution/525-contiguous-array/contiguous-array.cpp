// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
//
//
// Example 1:
//
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Example 2:
//
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//
//
//
// Note:
// The length of the given binary array will not exceed 50,000.
//


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //一个技巧：将0 1的出现次数转换为累加和。即遇到0则-1，遇到1则+1
        //在遍历过程中，我们不停将累加和存在一个hashmap中，如果后面的累加和之前出现在hashmap中
        //则说明某一段子串的累加和为0，即0和1的数目相等
        int ans = 0, len = nums.size(), sum = 0;
        unordered_map<int, int> m{{0, -1}};    //先存入一个0的映射，便于更新从数组起始的长度
        for (int i = 0; i < len; ++i) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (m.count(sum)) {
                ans = max(ans, i - m[sum]);
            }
            else m[sum] = i;
        }
        return ans;
    }
};
