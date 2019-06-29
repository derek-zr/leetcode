// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
// Example 1:
//
//
// Input: [5,7]
// Output: 4
//
//
// Example 2:
//
//
// Input: [0,1]
// Output: 0


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        //最后返回的即为m和n二进制位最左边相同的
        //例如5-7 101 110 111 最后结果为100
        //将m和n不断向右移，直到两者相等（找到左边相等的位）
        int i = 0;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            ++i;
        }
        
        return m<<i;
    }
};
