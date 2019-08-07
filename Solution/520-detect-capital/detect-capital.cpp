// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
//
// 	All letters in this word are capitals, like "USA".
// 	All letters in this word are not capitals, like "leetcode".
// 	Only the first letter in this word is capital, like "Google".
//
// Otherwise, we define that this word doesn't use capitals in a right way.
//
//  
//
// Example 1:
//
//
// Input: "USA"
// Output: True
//
//
//  
//
// Example 2:
//
//
// Input: "FlaG"
// Output: False
//
//
//  
//
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//


class Solution {
public:
    bool detectCapitalUse(string word) {
        //统计大写字母出现的次数
        int len = word.size();
        int cnts = 0;
        for(char c : word) {
            if(c >= 'A' && c <= 'Z') ++cnts;
        }
        //只出现了一次
        if(cnts == 1) return (word[0]>='A' && word[0]<='Z');
        //cout<<cnts<<len;
        return cnts == 0 || cnts == len;
    }
};
