// Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
//
// Example:
//
//
// Input: 13
// Output: 6 
// Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
//
//


class Solution {
public:
    int countDigitOne(int n) {
        //找数学规律。例如：56的1个数=(5+1)*1+10=16, 16的个数=(1+1)*1+6=8 加不加10取决于十位数是否大于等于2(可以用(n+2)/10来判断)
        //对于三位数，可以用同样的规则递推并累加
        long ans = 0, a = 1, b = 1;
        while(n > 0) {
            ans += (n+8)/10 * a + (n%10 == 1) * b;
            b += n%10 * a;
            a *= 10;
            n /= 10;
        }
        return ans;
    }
};
