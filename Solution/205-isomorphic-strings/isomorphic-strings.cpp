// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
//
//
// Input: s = "egg", t = "add"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
//
//
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.
//


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //对于一对字母映射，其上次出现的位置应该是相同的。否则说明该字母映射不成立
        //用两个数组记录上一次字母映射的下标
        if(s.size() != t.size()) return false;
        vector<int> index1(256,-1); //ascii码
        vector<int> index2(256,-1);
        int len =  s.size();
        
        for(int i = 0; i < len; ++i) {
            //当前遍历到的字母映射是否上次在同一下标出现过
            if(index1[s[i]] != index2[t[i]]) return false;
            index1[s[i]] = i;
            index2[t[i]] = i;
        }
        
        return true;
    }
};
