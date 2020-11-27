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
        //这道题是单调栈的经典问题，从尾部开始遍历，维持栈内的递减
        //环状数组可以视为在尾部再拼接一个数组，即从2*len-1遍历，取i%len
        int len = nums.size();
        vector<int> ans(len);
        stack<int> st;
        //从后向前遍历
        for (int i = 2*len-1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums[i % len]) {
                st.pop();
            }
            ans[i % len] = st.empty() ? -1 : st.top();
            st.push(nums[i % len]);
        }
        return ans;
    }
};
