// You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty. 
//
//
// For each move, you could choose any m (1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines  at the same time .  
//
// Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.
//
// Example1
//
// Input: [1,0,5]
//
// Output: 3
//
// Explanation: 
// 1st move:    1     0 <-- 5    =>    1     1     4
// 2nd move:    1 <-- 1 <-- 4    =>    2     1     3    
// 3rd move:    2     1 <-- 3    =>    2     2     2   
//
//
// Example2
//
// Input: [0,3,0]
//
// Output: 2
//
// Explanation: 
// 1st move:    0 <-- 3     0    =>    1     2     0    
// 2nd move:    1     2 --> 0    =>    1     1     1     
//
//
// Example3
//
// Input: [0,2,0]
//
// Output: -1
//
// Explanation: 
// It's impossible to make all the three washing machines have the same number of dresses. 
//
//
//
//
// Note:
//
// The range of n is [1, 10000].
// The range of dresses number in a super washing machine is [0, 1e5].
//
//


class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        //dp求解，详见https://blog.csdn.net/tstsugeg/article/details/62427718
        //主要思想是,对位置k上的洗衣机来说，如果左边k个洗衣机中（下标从0开始）原有衣服总数小于avg*k，表明左边k个洗衣机作为整体最终需要从右边洗衣机（包含位置k）中获取衣服，
        //而获取衣服必定需要通过位置k的洗衣机，右边同理。这里拿lCnt表示位置k左边所有洗衣机最终向右边洗衣机（包含位置k）输送的衣服数，如果lCnt小于0，
        //表示左边洗衣机最终需要从右边洗衣机中获取衣服，同理拿rCnt表示位置k右边所有洗衣机最终向左边洗衣机（包含位置k）中输送的衣服数。
        if (machines.empty())  return 0;
        int len = machines.size();
        vector<int> sum(len+1, 0);
        for (int i = 0; i < len; ++i) {
            sum[i+1] = sum[i] + machines[i];
        }
        //检查能不能整除
        if (sum[len] % len != 0)   return -1;
        int ans = INT_MIN, avg = sum[len] / len;
        
        //开始遍历
        for (int i = 0; i < len; ++i) {
            //计算左边和右边能够提供的dress数目
            int left = sum[i] - avg * i;
            int right = sum[len] - sum[i+1] - (len - i - 1) * avg;    //相当于是右边当前的总和减去最后需要的
            if (left > 0 && right > 0) {
                //说明k位置需要左边和右边提供dress，过程可以同时进行
                ans = max(ans, max(left, right));   //取最大值，即最多的步数
            }
            else if (left < 0 && right  < 0) {
                //说明k位置需要给左边和右边提供dress，这个过程不能同时进行
                ans = max(ans,  - left - right);
            }
            else {
                //说明k位置需要某一边提供，同时可以提供给另一边。这个过程是可以同时进行的
                ans = max(ans, max(abs(left), abs(right)));    //取绝对值的较大值，影响最终minimum moves的关键
            }
        }
        return ans;
    }
};
