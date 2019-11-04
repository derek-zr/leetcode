// A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
//
// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
// Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
//
// Example 1:
//
//
// Input: [1,7,4,9,2,5]
// Output: 6
// Explanation: The entire sequence is a wiggle sequence.
//
//
// Example 2:
//
//
// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
//
//
// Example 3:
//
//
// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2
//
// Follow up:
// Can you do it in O(n) time?
//
//
//


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //https://www.cnblogs.com/grandyang/p/5697621.html
        
        //第二种方法是贪心，从上面链接评论图可以看出，在找到大于或小于的序列时，无需比较大小，直接更新即可，因为一定能够组成更长的子序列
        if (nums.empty())  return 0;
        int positive = 1, negative = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1])  positive = negative + 1;
            else if (nums[i] < nums[i-1])  negative = positive + 1;
        }
        return max(positive, negative);
        
        /*
        //第一种方法是dp，由于是寻找子序列，根据当前的差值是正还是负可以建立两个dp数组
        //分别表示到i位置的差值为正或负的最大子序列长度
        if (nums.empty())  return 0;
        int len = nums.size();
        vector<int> positive(len, 1);
        vector<int> negative(len, 1);
        //dp
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    //can add one positive seq to the neg seq end with j
                    positive[i] = max(positive[i], negative[j] + 1);
                }
                else if (nums[i] < nums[j]){
                    negative[i] = max(negative[i], positive[j] + 1);
                } 
            }
        }
        return max(positive.back(), negative.back());
        */
    }
};
