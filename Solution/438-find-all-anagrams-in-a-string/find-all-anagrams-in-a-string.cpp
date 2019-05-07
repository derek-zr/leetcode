// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
//
//
//
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
//


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //用两个哈希表
        if (s.empty()) return {};
        vector<int> res, m1(256, 0), m2(256, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++m1[s[i]]; ++m2[p[i]];
        }
        if (m1 == m2) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++m1[s[i]]; 
            --m1[s[i - p.size()]];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        return res;
    
        /*vector<int> ans;
        vector<int> cnts(26,0);
        //建立p的字母频次表
        for(char c : p) ++cnts[c-'a'];
        
        int i = 0;
        int len = s.size();
        int lenp = p.size();
        while(i <= len-lenp) {
            int j = 0;
            vector<int> tmp = cnts;
            for(j; j < lenp; ++j) {
                if(tmp[s[i+j]-'a'] <= 0) {break;}
                else --tmp[s[i+j]-'a'];
            }
            if(j == lenp) ans.push_back(i);
            ++i;
        }
        return ans;*/
    }
};
