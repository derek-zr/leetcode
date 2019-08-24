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
    int divide(int a, int b) {
        // Edge case: INT_MIN is the only value that cannot be sign-flipped with absolute
        // value.  This causes all kinds of problems in the general algorithm, so we explicitly
        // handle "divide by 1" identity cases.  In all other cases, we increment INT_MIN so it
        // will successfully sign-flip - and given how imprecise integer division is, we should
        // be able to get away with it.
        int absABoost = 0;
        
        if (a == numeric_limits<int>::min()) {
            if (b == -1) { return numeric_limits<int>::max(); }
            else if (b == 1) { return numeric_limits<int>::min(); }
            else { ++a; absABoost = 1; }
        }

        if (b == numeric_limits<int>::min()) {
            if (a == numeric_limits<int>::max()) {
                return 0; // min has a larger absolute value (by 1) than max.
            } else {
                ++b;
            }
        }

        // Fast reject: If we're dividing an integer by a larger number, quit and return 0 now.
        // The larger number will not fit inside the smaller number.
        if (a < 0 && b < a) {
            return 0;
        }
        else if (a > 0 && b > a) {
            return 0;
        }

        unsigned int absA = abs(a);
        unsigned int absB = abs(b);
        int quotient = 0;

        while (static_cast<int>(absA) >= static_cast<int>(absB)) {
            int bit = 0;
            while (bit <= 29 && (absA+absABoost >= (absB << (bit+1)))) {
                ++bit;
            }

            quotient += (1 << bit);
            absA -= (absB << bit);
        }

        if ((a > 0) == (b > 0)) {
            return quotient;
        } else {
            return -quotient;
        }
        
        /*
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
        */
    }
};
