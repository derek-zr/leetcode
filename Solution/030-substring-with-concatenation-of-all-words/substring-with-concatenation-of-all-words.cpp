// You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.
//
// You can return the answer in any order.
//
//  
// Example 1:
//
//
// Input: s = "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
//
// Example 2:
//
//
// Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// Output: []
//
//
// Example 3:
//
//
// Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// Output: [6,9,12]
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 104
// 	s consists of lower-case English letters.
// 	1 <= words.length <= 5000
// 	1 <= words[i].length <= 30
// 	words[i] consists of lower-case English letters.
//
//


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //用滑动窗口法，hashmap保存字典中词的数目
        vector<int> ans;
        if(s.empty() || words.empty()) return ans;
        int len = s.size(),dictlen = words.size(),cnt = dictlen,wordlen=words[0].size();
        unordered_map<string,int> m;
        for(string tmp : words) ++m[tmp];
        //开始循环
        for(int i = 0; i <= len-dictlen*wordlen; i++) {
            unordered_map<string,int> cnts;
            int j = 0;
            for(j; j < dictlen; ++j) {
                string tmp = s.substr(i+j*wordlen,wordlen);  //一个窗口
                if(m.find(tmp) != m.end()) {
                    ++cnts[tmp];  //在字典中
                    if(cnts[tmp] > m[tmp]) break;  //但重复出现了，跳过
                }
                else break; //当前窗口没出现在字典里，跳过
            }
            if(j == dictlen) ans.push_back(i);
        }
        return ans;
    }
};
