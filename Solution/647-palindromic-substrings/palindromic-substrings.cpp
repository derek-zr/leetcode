// Given a string, your task is to count how many palindromic substrings in this string.
//
// The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
//
// Example 1:
//
//
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
//
//
//  
//
// Example 2:
//
//
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//
//
//  
//
// Note:
//
//
// 	The input string length won't exceed 1000.
//
//
//  


class Solution {
public:
    bool isPalin(string &str,int start,int end)
    {
        while(start<=end)
        {
            if(str[start]!=str[end]){
                return false;
                break;
            }
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int counts=0;
        for(int i=0;i<s.size();i++){
            counts++;  //单个字符就是回文
            for(int k=i-1;k>=0;k--){
                if(isPalin(s,k,i)) counts++;
            }
        }
        return counts;
    }
};
