// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,3,2]
// Output: 3
//
//
// Example 2:
//
//
// Input: [0,1,0,1,0,1,99]
// Output: 99
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //统计所有元素的第i个bit上为1的个数，因为题目说了其它元素出现了3次，而特殊元素只出现了1次，所以当统计的个数不能整除3就表明特殊元素在第i个bit上是1，所以我们把结果的第i个bit设为1，通过检查32个bit，这样我们就构造出了最后的结果
        int ans = 0;
        int sum = 0;  //用于记录某一位1出现的次数
        
        for(int i = 0; i < 32; ++i) {
            sum = 0;
            for(int n : nums) {
                sum += ((n>>i) & 1); //第i位是否为1
            }
            ans |= (sum % 3) << i;  //是否出现了三次
        }
        
        return ans;
    }
};
