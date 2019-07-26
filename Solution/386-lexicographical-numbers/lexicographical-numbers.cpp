// Given an integer n, return 1 - n in lexicographical order.
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
//


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = cur;
            if(cur * 10 <= n) {  //从高位开始遍历起
                cur *= 10;
            }
            else {
                if(cur >= n) cur /= 10;
                cur += 1;   //自加遍历
                while(cur % 10 == 0) cur /= 10;  //如果+1导致末尾出现了很多0，则需要把末尾的0都去掉。比如19+1=20，需要变为2.
            }
        }
        return ans;
    }
};
