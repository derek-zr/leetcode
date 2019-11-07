// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].
//


class Solution {
public:
    string convertToBase7(int num) {
        //递归方法解决
        if (num < 0) return "-" + convertToBase7(-num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }
};
