// Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
//
// To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
//
// Example:
//
//
// Input:
// A = [ 1, 2]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2]
//
// Output:
// 2
//
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
//
//
//  
//


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        //分别记录AB、CD中两两数字相加的结果，记录在hashmap中
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        
        int len = A.size();
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                ++m1[A[i]+B[j]];
                ++m2[C[i]+D[j]];   //某一个和值出现的次数
            }
        }
        int ans = 0;
        for(auto p : m1) {
            ans += (p.second * m2[-p.first]);  //这里注意是相乘，因为是全排列
        }
        
        return ans;
    }
};
