// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:
//
//
// 	Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// 	Paste: You can paste the characters which are copied last time.
//
//
//  
//
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
//
// Example 1:
//
//
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
//
//
//  
//
// Note:
//
//
// 	The n will be in the range [1, 1000].
//
//
//  
//


//如果i是j的倍数，那么i可以通过粘贴(i/j-1)次j 得到, 再加上一次复制操作，那么可以通过dp[j]+i/j 次操作得到dp[i] .

class Solution {
public:
    int minSteps(int n) {
       vector<int> dp(n+1,INT_MAX);
       dp[0]=dp[1]=0;
       for(int i=2;i<=n;i++){
           for(int j=1;j<i;j++){
               if(i%j==0) dp[i]=min(dp[i],dp[j]+i/j);
           }
       }
       return dp[n];
    }
};
