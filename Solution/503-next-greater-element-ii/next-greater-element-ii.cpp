//
// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
//
//
// Example 1:
//
// Input: [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; The number 2 can't find next greater number; The second 1's next greater number needs to search circularly, which is also 2.
//
//
//
// Note:
// The length of given array won't exceed 10000.
//


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //第二种方法，用stack缓存之前遇到的数
        int len = nums.size();
        vector<int> ans(len, -1);
        stack<int> st;
        //遍历两遍，第二遍是为了填上所有之前压入的数字的greater element
        for (int i = 0; i < 2 * len; ++i) {
            int num = nums[i % len];
            while (!st.empty() && nums[st.top()] < num) {
                ans[st.top()] = num;
                st.pop();
            }
            if (i < len)  st.push(i);
        }
        
        return ans;
        
        /*
        //第一种是暴力方法，对于每一个数字，遍历其左边的所有数字(并包含其前面的部分)
        int len = nums.size();
        vector<int> ans(len, -1);
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < i + len; ++j) {
                if (nums[j % len] > nums[i]) {
                    ans[i] = nums[j % len];
                    break;
                }
            }
        }
        return ans;
        */
    }
};
