// Write a program to find the nth super ugly number.
//
// Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k.
//
// Example:
//
//
// Input: n = 12, primes = [2,7,13,19]
// Output: 32 
// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 
//              super ugly numbers given primes = [2,7,13,19] of size 4.
//
// Note:
//
//
// 	1 is a super ugly number for any given primes.
// 	The given numbers in primes are in ascending order.
// 	0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
// 	The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
//
//


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //动态规划。每次从质数数组中取出一个相乘后的最小值
        //例如：1,2,2*2,7*1,4*2....
        int len = primes.size();
        //indexes表示各质数现在乘到哪个下标了
        vector<int> dp(n,1), indexes(len,0);
        
        for(int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for(int j = 0; j < len; ++j) {
                dp[i] = min(dp[i], dp[indexes[j]]*primes[j]);
            }
            //更新下标值
            for(int j = 0; j < len; ++j) {
                if(dp[i] == dp[indexes[j]]*primes[j]) ++indexes[j];
            }
        }
        
        return dp.back();
    }
};
