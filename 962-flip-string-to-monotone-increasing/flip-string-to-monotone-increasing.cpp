// A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)
//
// We are given a string S of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.
//
// Return the minimum number of flips to make S monotone increasing.
//
//  
//
//
// Example 1:
//
//
// Input: "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
//
//
//
// Example 2:
//
//
// Input: "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.
//
//
//
// Example 3:
//
//
// Input: "00011000"
// Output: 2
// Explanation: We flip to get 00000000.
//
//
//  
//
// Note:
//
//
// 	1 <= S.length <= 20000
// 	S only consists of '0' and '1' characters.
//
//
//
//


class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len = S.size();
        if(len==0) return 0;
        vector<int> dp0(len,0);  //前i个字符的最少翻转次数，且结尾为0
        vector<int> dp1(len,0);  //前i个字符的最少翻转次数，且结尾为1
        dp0[0] = S[0]=='0' ? 0 :1;
        dp1[0] = S[0]=='1' ? 0 :1;
        
        for(int i=1;i<len;i++){
            dp0[i] = dp0[i-1] + (S[i]=='0'?0:1);
            dp1[i] = min(dp0[i-1],dp1[i-1]) + (S[i]=='1'?0:1);
        }
        
        return min(dp0[len-1],dp1[len-1]);
    }
};
