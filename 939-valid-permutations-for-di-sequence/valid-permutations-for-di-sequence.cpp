// We are given S, a length n string of characters from the set {'D', 'I'}. (These letters stand for "decreasing" and "increasing".)
//
// A valid permutation is a permutation P[0], P[1], ..., P[n] of integers {0, 1, ..., n}, such that for all i:
//
//
// 	If S[i] == 'D', then P[i] > P[i+1], and;
// 	If S[i] == 'I', then P[i] < P[i+1].
//
//
// How many valid permutations are there?  Since the answer may be large, return your answer modulo 10^9 + 7.
//
//  
//
// Example 1:
//
//
// Input: "DID"
// Output: 5
// Explanation: 
// The 5 valid permutations of (0, 1, 2, 3) are:
// (1, 0, 3, 2)
// (2, 0, 3, 1)
// (2, 1, 3, 0)
// (3, 0, 2, 1)
// (3, 1, 2, 0)
//
//
//  
//
// Note:
//
//
// 	1 <= S.length <= 200
// 	S consists only of characters from the set {'D', 'I'}.
//
//
//
//  
//
//


class Solution {
public:
    int numPermsDISequence(string S) {
        int len = S.size()+1;
        long long mod = 1e9+7;
        long long dp[len+1][len+1]; //长度为i，以j结束的序列个数
        long long pre_sum[len+1][len+1]; //dp的前缀和
        memset(dp,0,sizeof(dp));
        memset(pre_sum,0,sizeof(pre_sum));
        dp[1][1] = 1;
        for(int i=1;i<=len;i++) pre_sum[1][i] = pre_sum[1][i-1] + dp[1][i];
        //dp
        long long ans = 0;
        for(int i=2;i<=len;i++){
            for(int j=1;j<=i;j++){
                if(S[i-2]=='D'){
                    dp[i][j] = (pre_sum[i-1][len]-pre_sum[i-1][j-1]+mod) % mod;
                }
                else{
                    dp[i][j] = pre_sum[i-1][j-1] % mod;
                }
                
                if(i==len) ans = (ans+dp[i][j]) % mod;
            }
            //更新前缀和
            for(int j=1;j<=len;j++) pre_sum[i][j] = pre_sum[i][j-1] + dp[i][j];
        }
        
        return ans;
    }
};
