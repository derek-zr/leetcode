// Given an integer, write a function to determine if it is a power of two.
//
// Example 1:
//
//
// Input: 1
// Output: true 
// Explanation: 20 = 1
//
//
// Example 2:
//
//
// Input: 16
// Output: true
// Explanation: 24 = 16
//
// Example 3:
//
//
// Input: 218
// Output: false
//


class Solution {
public:
    bool isPowerOfTwo(int n) {
       //2的幂次即10000000....  那n-1就是0111111...
       //所以n & n-1 应该为0 
       if(n <= 0) return false;
       if( n & (n-1)) return false;
       else return true;
    }
};
