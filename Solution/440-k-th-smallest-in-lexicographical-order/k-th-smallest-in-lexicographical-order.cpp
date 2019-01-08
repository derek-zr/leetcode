// Given integers n and k, find the lexicographically k-th smallest integer in the range from 1 to n.
//
// Note: 1 ≤ k ≤ n ≤ 109.
//
// Example:
//
// Input:
// n: 13   k: 2
//
// Output:
// 10
//
// Explanation:
// The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//
//
//


class Solution {
public:
    int findKthNumber(int n, int k) {
        //十叉树，例如 1 的子节点有10,11，……19,10的子节点又有100,101，……，109
        int cur = 1;  //从1开始
        --k;  //去掉第一个
        while(k>0){
            long long step = 0;  //记录当前为第几个
            long long first = cur;  //这里一定要用long long 不然会溢出导致结果错误
            long long last = cur + 1;
            while(first<=n){  //找出如10-20,100-200这样的区间
                step += min( (long long)n + 1,last)-first;
                first *= 10;
                last *= 10;
            }
            
            if(step<=k){  //如果当前步数仍小于k,则说明我们可以直接加当前值（如从1到2）
                cur++;
                k -= step;
            }
            else {        //如果当前步数大于k，则说明我们要找的值在子节点中（如1下面的第一个子节点10），再重复上述过程寻找子节点（可以是子节点的子节点）
                cur = cur *10;
                k--;
            }
        }
        return cur;
    }
};
