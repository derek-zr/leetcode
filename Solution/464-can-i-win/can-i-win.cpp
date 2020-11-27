// In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. The player who first causes the running total to reach or exceed 100 wins.
//
// What if we change the game so that players cannot re-use integers?
//
// For example, two players might take turns drawing from a common pool of numbers from 1 to 15 without replacement until they reach a total >= 100.
//
// Given two integers maxChoosableInteger and desiredTotal, return true if the first player to move can force a win, otherwise return false. Assume both players play optimally.
//
//  
// Example 1:
//
//
// Input: maxChoosableInteger = 10, desiredTotal = 11
// Output: false
// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.
//
//
// Example 2:
//
//
// Input: maxChoosableInteger = 10, desiredTotal = 0
// Output: true
//
//
// Example 3:
//
//
// Input: maxChoosableInteger = 10, desiredTotal = 1
// Output: true
//
//
//  
// Constraints:
//
//
// 	1 <= maxChoosableInteger <= 20
// 	0 <= desiredTotal <= 300
//
//


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        //暴力递归模拟，但需要记录中间状态剪枝
        //大于目标值则一定赢
        if(maxChoosableInteger >= desiredTotal) return true;
        //所有可能值求和后仍小于，则都不可能赢
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int,bool> m;
        return helper(maxChoosableInteger,desiredTotal,0,m);
    }
    

    bool helper(int maxChoosableInteger, int desiredTotal,int used,unordered_map<int,bool> &m) {
        //used 32bit的整型数表示已经使用的数字
        if(m.count(used)) return m[used];  //该状态之前已经计算过
        for(int i = 0; i < maxChoosableInteger; ++i) {
            //用bitmap记录当前使用的值
            int cur = (1 << i);
            if((cur & used) == 0) {  //未使用过
                //加上i已经超过当前值（赢了）或者对方输(传递used状态)
                if(desiredTotal <= i+1 || !helper(maxChoosableInteger,desiredTotal-(i+1),cur | used,m)) {
                    m[used] = true;
                    return true;
                }
            }
        }
        //不能赢
        m[used] = false;
        return false;
    }
};
