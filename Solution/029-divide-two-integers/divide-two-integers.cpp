// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 ||(dividend==INT_MIN && divisor==-1)) return INT_MAX;  //处理特殊情况
        long long dd = abs((long long)dividend),dr = abs((long long)divisor);
        if(dd < dr) return 0;
        
        long long ans = 0;
        bool sign = (dividend<0) ^ (divisor<0) ? false : true;
        
        //每次进行位操作
        while(dd >= dr) {
            long long tmp_subnum=dr,tmp_dr = 1;
            while(dd >= (tmp_subnum<<1)) {
                tmp_subnum <<=1;
                tmp_dr <<= 1;         
            }
            
            ans += tmp_dr;  //加上这一趟的除数
            dd -= tmp_subnum;  //减去这一趟已经相乘得到的最大数
        }
        
        return sign ? ans : -ans;
    }
};
