// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
//
// Input: s = "anagram", t = "nagaram"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "rat", t = "car"
// Output: false
//
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
//


class Solution {
public:
    bool isAnagram(string s, string t) {
    int count[26]={0};   
    if(s.size()!=t.size())
        return false;
    for(int i=0;i<s.size();i++){
       count[s[i]-'a']++;
       count[t[i]-'a']--;
    }
   for(int j=0;j<26;j++){
       if(count[j])
           return false;
       }
        return true;
    }
};
