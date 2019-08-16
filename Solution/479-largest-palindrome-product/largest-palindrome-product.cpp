// Find the largest palindrome made from the product of two n-digit numbers.
//
// Since the result could be very large, you should return the largest palindrome mod 1337.
//
//  
//
// Example:
//
// Input: 2
//
// Output: 987
//
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
//
//  
//
// Note:
//
// The range of n is [1,8].
//


class Solution {
public:
    int largestPalindrome(int n) {
        //对于每个遍历到的数字，我们用当前数字当作回文数的前半段，将其翻转一下拼接到后面，此时组成一个回文数，这里用到了一个规律，当n>1时，两个n位数乘积的最大回文数一定是2n位的。下面我们就要来验证这个回文数能否由两个n位数相乘的来
        int upper = pow(10,n)-1 , lower = upper / 10;
        //从大往小遍历
        for(int i = upper; i > lower; --i) {
            string tmp = to_string(i);
            //拼接一个回文串
            long pa = stol(tmp + string(tmp.rbegin(),tmp.rend()));
            for(long j = upper; j*j > pa; --j) {  //找较大的数，则遍历到平方根位置即可停止
                if(pa % j == 0) return pa % 1337;
            }
        }
        return 9;
    }
};
