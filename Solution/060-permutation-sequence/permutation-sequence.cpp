// The set [1,2,3,...,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//
// 	"123"
// 	"132"
// 	"213"
// 	"231"
// 	"312"
// 	"321"
//
//
// Given n and k, return the kth permutation sequence.
//
// Note:
//
//
// 	Given n will be between 1 and 9 inclusive.
// 	Given k will be between 1 and n! inclusive.
//
//
// Example 1:
//
//
// Input: n = 3, k = 3
// Output: "213"
//
//
// Example 2:
//
//
// Input: n = 4, k = 9
// Output: "2314"
//
//


class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "", nums = "";
        for (int i = 1; i <= n; ++i)
            nums += (i + '0');
        if (k == 1) return nums;
        //计算阶乘
        vector<int> fac(n, 1);
        for (int i = 1; i < n; ++i) 
            fac[i] = fac[i-1] * i;
        //逐个位置确定
        --k;  //下标从0开始
        int index = n-1;
        for (index; index >= 0; --index) {
            ans += nums[k / fac[index]];
            nums.erase(k / fac[index], 1);   //已经确定的数字就可以从备选列表里面删除了
            k = k % fac[index];
        }
        return ans;
    }
};
