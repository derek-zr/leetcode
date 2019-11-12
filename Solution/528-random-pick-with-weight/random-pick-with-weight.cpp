// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.
//
// Note:
//
//
// 	1 <= w.length <= 10000
// 	1 <= w[i] <= 10^5
// 	pickIndex will be called at most 10000 times.
//
//
// Example 1:
//
//
// Input: 
// ["Solution","pickIndex"]
// [[[1]],[]]
// Output: [null,0]
//
//
//
// Example 2:
//
//
// Input: 
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// Output: [null,0,1,1,1,0]
//
//
// Explanation of Input Syntax:
//
// The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.
//


class Solution {
public:
    //这道题相当于带权重的random，一个trick是我们可以累加整个数组
    //例如[1,2],那么累加后得到3.即我们在3范围内random，为0的话就是0， 为1或2的话就是1，就能达到加权随机的目的了
    Solution(vector<int>& w) {
        sum = w;
        for (int i = 1; i < w.size(); ++i) {
            sum[i] = sum[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int x = rand() % sum.back();   //在累加和的范围内随机
        int left = 0, right = sum.size();
        //二分查找第一个下标对应值大于x的
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= x)  left = mid + 1;
            else right = mid;
        }
        return right;
    }
private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
