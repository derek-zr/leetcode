// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
// Example:
//
//
// Input:  [1,2,1,3,2,5]
// Output: [3,5]
//
// Note:
//
//
// 	The order of the result is not important. So in the above example, [5, 3] is also correct.
// 	Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //参考single number第一题的解法，也是用异或。但这道题因为有两个只出现过一次的数字，最后整个数组异或出来的结果是两个数字的异或结果。
        //所以我们需要考虑如何区分出这两个数字。
        //对于题目中的例子，3(11),5(101) 整个数组异或后得到110(异或结果中为1的bit位即代表两个数字在这个位置上有差别)，然后我们通过a &= -a 得到最右边的第一个1，即10。可以看出3和5也是从第二位开始有了差别，因此通过将10与各个数组与，可以将数组分为两个部分，一部分含有3，一部分含有5
        vector<int> ans(2,0);
        int diff = nums[0];
        int len = nums.size();
        for(int i = 1; i < len; ++i) {
            diff ^= nums[i];
        }
        diff &= -diff;
        for(int num : nums) {
            if(diff & num) ans[0] ^= num;
            else ans[1] ^= num;
        }
        return ans;
    }
};
