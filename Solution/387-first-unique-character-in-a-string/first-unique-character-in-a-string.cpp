//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
     int count[26]={0};
     for(int i=0;i<s.size();i++){
     	count[s[i]-'a']++;
     }
     int i=0;
     while(i<s.size()&&count[s[i]-'a']>1) ++i;
     return i==s.size() ? -1:i;
    }
};
