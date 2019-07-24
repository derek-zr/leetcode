// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
//
//
// Input: 16
// Output: true
//
//
//
// Example 2:
//
//
// Input: 14
// Output: false
//
//
//


class Solution {
public:
    bool isPerfectSquare(int num) {
        //二分法
        int left = 1 , right = num;
        
        while(left <= right) {
            int mid = left + (right-left)/2;
            int res = num/mid, remain = num % mid;
            //避免使用mid*mid，防止溢出
            if(remain == 0 && res == mid) return true;
            else if(res < mid) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};
