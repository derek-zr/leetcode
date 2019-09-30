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
    vector<int> majorityElement(vector<int>& nums) {
        //与之前majority element相同的投票法
        //随机初始化数组头为结果，在遍历过程中，如果计数值等于0，则更新备选值
        //最后得到的备选值经过验证即为最终的结果
        //一个不同的点在于，因为大于n/3次数的可能最多有两个结果，所以需要两个计算器
        
        int n = nums.size();
        if (n == 0)   return {};
        if (n == 1)   return { nums[0] };
        //if (n == 2)   return { nums[0], nums[1]};
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        int res1 = nums[0], res2 = nums[0];
        //遍历计数
        for (int num : nums) {
            if (num == res1) ++cnt1;
            else if (num == res2) ++cnt2;
            else if (cnt1 == 0) { res1 = num; cnt1 = 1; }
            else if (cnt2 == 0) { res2 = num; cnt2 = 1; }
            else { --cnt1; --cnt2; }
        }
        cnt1 = 0;
        cnt2 = 0;
        //验证答案
        for (int num : nums) {
            if (res1 == num) ++cnt1;
            else if (res2 == num) ++cnt2;
        }
        if (cnt1 > n/3)  ans.push_back(res1);
        if (cnt2 > n/3)  ans.push_back(res2);
        return ans;
    }
};
