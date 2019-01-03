// Implement int sqrt(int x).
//
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
//
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
//
//
// Input: 4
// Output: 2
//
//
// Example 2:
//
//
// Input: 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since 
//              the decimal part is truncated, 2 is returned.
//
//


/*
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.50%)
 * Total Accepted:    270.6K
 * Total Submissions: 917.1K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

//https://blog.csdn.net/hnu2012/article/details/72598038
class Solution {
public:
    int mySqrt(int x) {
       if(x==0||x==1)
        return x;
        double x0=x;
        double t=x;
        x0=x0/2+t/(2*x0);
        while(fabs(x0*x0-t)>0.00001)
        {
            x0=x0/2+t/(2*x0);
        }
        cout<<x0<<endl;
        return int(x0);
    }
};

/*
二分查找法
int mySqrt(int x) 
{
    if(x==0||x==1)
        return x;
    int mid,left=1,right=x;
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(mid>x/mid)
            right=mid-1;
        else if(mid==x/mid)
            return mid;
        else
        {
            if((mid+1)>x/(mid+1))
                return mid;
            if((mid+1)==x/(mid+1))
                return mid+1;
            left=mid+1;
        }
    }
    return (left+right)/2;
}

*/

