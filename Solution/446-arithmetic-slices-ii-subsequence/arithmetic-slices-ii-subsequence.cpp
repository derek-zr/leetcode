// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
// For example, these are arithmetic sequences:
//
//
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
//
// The following sequence is not arithmetic.
//
//
// 1, 1, 2, 5, 7
//  
//
// A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
//
// A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
//
// The function should return the number of arithmetic subsequence slices in the array A.
//
// The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
//  
//
// Example:
//
//
// Input: [2, 4, 6, 8, 10]
//
// Output: 7
//
// Explanation:
// All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]
//
//


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        //思路：很明显用到动态规划，那怎么定义dp数组就很关键
        //由于等差数列与diff的关系很大，所以很明显一维dp数组很难找到dp关系
        //但是如果将diff加入，作为二维dp数组，diff的范围很大，没办法确定数组的大小
        //所以考虑一个dp数组，其每个元素不是子序列的数目，而index和一个diff与diff出现次数的映射
        int ans = 0;
        int len = A.size();
        vector<unordered_map<int,int>> dp(len);
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                //int diff = A[i] - A[j]; 可能溢出！！！
                long tmp = (long)A[i] - A[j];
                if(tmp > INT_MAX || tmp < INT_MIN) continue;
                int diff = (int)tmp;
                //增加diff次数
                ++dp[i][diff];
                //如果dp[j]也出现过这个diff，则说明至少存在k/j/i一组符合条件的
                if(dp[j].count(diff)) {
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return ans;
    }
};
