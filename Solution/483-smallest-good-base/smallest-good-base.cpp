// For an integer n, we call k>=2 a good base of n, if all digits of n base k are 1.
//
// Now given a string representing n, you should return the smallest good base of n in string format.
//
// Example 1:
//
//
// Input: "13"
// Output: "3"
// Explanation: 13 base 3 is 111.
//
//
//  
//
// Example 2:
//
//
// Input: "4681"
// Output: "8"
// Explanation: 4681 base 8 is 11111.
//
//
//  
//
// Example 3:
//
//
// Input: "1000000000000000000"
// Output: "999999999999999999"
// Explanation: 1000000000000000000 base 999999999999999999 is 11.
//
//
//  
//
// Note:
//
//
// 	The range of n is [3, 10^18].
// 	The string representing n is always valid and will not have leading zeros.
//
//
//  
//


class Solution {
public:
    string smallestGoodBase(string n) {
        //https://www.cnblogs.com/grandyang/p/6620351.html
        long long num = stol(n);
        for (int i = log(num + 1) / log(2); i >= 2; --i) {
            long long left = 2, right = pow(num, 1.0 / (i - 1)) + 1;
            while (left < right) {
                long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
    }
};
