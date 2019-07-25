//
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom 
// note can be constructed from the magazines ; otherwise, it will return false. 
//
//
// Each letter in the magazine string can only be used once in your ransom note.
//
//
// Note:
// You may assume that both strings contain only lowercase letters.
//
//
//
// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true
//
//


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //建立一个hash表，统计字符出现的次数
        vector<int> m(26,0);
        int len1 = magazine.size() ,  len2 = ransomNote.size();
        
        for(int i = 0; i < len1 ; ++i) {
            ++m[magazine[i]-'a'];
        }
        
        for(int i = 0; i < len2; ++i) {
            if(--m[ransomNote[i]-'a'] < 0) return false;
        }
        
        return true;
    }
};
