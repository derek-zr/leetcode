// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.
//


class Solution {
public:
    int jump(vector<int>& nums) {
        //统计当前能够调到最远范围内，是否存在位置可以直接跳到终点
        int ans = 0;
        int cur_index = 0, pre_index = 0;
        int len = nums.size();
        while(cur_index < len-1) {
            ++ans;  //必须跳一次
            int start = pre_index;  //保存上一次能跳到的最远距离
            pre_index = cur_index;  //更新为当前能跳到的最远距离
            for(int i = start; i <= pre_index; ++i) {
                cur_index = max(cur_index, i + nums[i]);
            }
            //cout<<cur_index;
        }
        return ans;
    }
};
