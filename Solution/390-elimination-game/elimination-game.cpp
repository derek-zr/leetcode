//
// There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
//
// Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
//
// We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
//
// Find the last number that remains starting with a list of length n.
//
// Example:
//
// Input:
// n = 9,
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
//
// Output:
// 6
//
//


class Solution {
public:
    int lastRemaining(int n) {
        return helper(n , true);
    }
    
    int helper(int n , bool left2right) {
        if(n == 1) return 1;
        //如果从右往左
        //[1,2,3,4] = 2*[1,2]  [1,2,3,4,5] = 2*[1,2]
        if(left2right) return 2*helper(n/2 , false);
        else {
            //奇偶情况不同
            //[1,2,3,4] = [1,3] = 2*[1,2]-1
            //[1,2,3,4,5] = [2,4] = 2*[1,2]
            return 2*helper(n/2,true) - 1 + n%2;
        }
    }
};
