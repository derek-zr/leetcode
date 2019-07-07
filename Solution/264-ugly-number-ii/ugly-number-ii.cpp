// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//


class Solution {
public:
    int nthUglyNumber(int n) {
        //用dp做，dp[i] = min(dp[p2]*2,dp[p3]*3,dp[p5]*5)。p2/p3/p5分别表示当前2/3/5移动到的下标，因为下一个最小值一定是已在数组中的数乘以2/3/5得到的。
        vector<int> ans(n,1);
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; ++i) {
            ans[i] = min(ans[p2]*2,min(ans[p3]*3,ans[p5]*5));
            if(ans[i] == ans[p2]*2) ++p2;
            //这里不需要用else。因为对于6这样的数来说，p2/p3都需要往前移动
            if(ans[i] == ans[p3]*3) ++p3;
            if(ans[i] == ans[p5]*5) ++p5;  
        }
        
        return ans.back();
    }
};
