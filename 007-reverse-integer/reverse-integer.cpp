// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
//
//
// Input: 123
// Output: 321
//
//
// Example 2:
//
//
// Input: -123
// Output: -321
//
//
// Example 3:
//
//
// Input: 120
// Output: 21
//
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//


/*
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.41%)
 * Total Accepted:    466.4K
 * Total Submissions: 1.9M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        bool sign=true;
        vector<int> ans;
        long result=0;
        if(x<0) {sign=false;x=-x;}
        while(x){
            int tmp=x%10;
            ans.push_back(tmp);
            x/=10;
        }
        int i=0;
        while(ans[i]==0) i++;
        for(i;i<ans.size();i++) result=10*result+ans[i];
        if(result<INT_MIN||result>INT_MAX) return 0;
        if(!sign) return -result;
        return result; 
    }
};

