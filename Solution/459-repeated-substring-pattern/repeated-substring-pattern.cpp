// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
//
//  
//
// Example 1:
//
//
// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
//
//
// Example 2:
//
//
// Input: "aba"
// Output: False
//
//
// Example 3:
//
//
// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
//
//


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i = len/2; i >= 1; --i) {
            if(len % i == 0) {  //必要条件
                int repeats = len / i;
                //判断前后缀是否相等
                if(s.substr(i) == s.substr(0,len-i)) return true;
                /*
                //尝试重复多次，判断是否相等
                string tmp = "";
                while(repeats--) tmp += s.substr(0,i);
                if(tmp == s) return true;
                */
            }
        }
        return false;
    }
};
