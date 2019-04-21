// Given an integer, write a function to determine if it is a power of three.
//
// Example 1:
//
//
// Input: 27
// Output: true
//
//
// Example 2:
//
//
// Input: 0
// Output: false
//
// Example 3:
//
//
// Input: 9
// Output: true
//
// Example 4:
//
//
// Input: 45
// Output: false
//
// Follow up:
// Could you do it without using any loop / recursion?


class Solution {
public:
    bool isPowerOfThree(int n) {
        //对数换底公式
        return (n > 0 && int(log10(n)/log10(3)) - log10(n)/log10(3) == 0);
    }
};
