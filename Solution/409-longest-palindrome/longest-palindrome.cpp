// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
//
// This is case sensitive, for example "Aa" is not considered a palindrome here.
//
// Note:
// Assume the length of given string will not exceed 1,010.
//
//
// Example: 
//
// Input:
// "abccccdd"
//
// Output:
// 7
//
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
//
//


class Solution {
public:
    int longestPalindrome(string s) {
        //统计出现奇数次的字母次数odds，需要从最终结果中减去odds（即每个奇数去1为偶数），最后还需要保留中间的一个字母(eg. dccaccd)
        vector<int> cnts(256);
        for(char c : s) ++cnts[c];
        int odds = 0;
        for(int cnt : cnts) odds += cnt&1;
        return s.size() - odds + (odds > 0);
    }
};
