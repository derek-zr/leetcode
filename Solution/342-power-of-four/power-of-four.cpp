// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example 1:
//
//
// Input: 16
// Output: true
//
//
//
// Example 2:
//
//
// Input: 5
// Output: false
//
//
// Follow up: Could you solve it without loops/recursion?


class Solution {
public:
    bool isPowerOfFour(int num) {
        //位操作
        //n&(n-1)用来判断是否可以被2整除。对于4的指数，其二进制表示的所有1一定出现在奇数位置上(1,100,10000)
        return (num > 0) && ((num&(num-1)) == 0) && ((num & 0x55555555) == num);
    }
};
