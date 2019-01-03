// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
//
//
// Example:
//
//
// Input: 2
// Output: 91 
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
//              excluding 11,22,33,44,55,66,77,88,99
//
//


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int dp[n+1];
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++){
            int multi=9;
            int k=9,count=1;
            while(count<i){
                multi*=k;
                k--;
                count++;
            }
            dp[i]=multi+dp[i-1];
        }
        if(n<=10) return dp[n];
        return dp[10];
    }
};
