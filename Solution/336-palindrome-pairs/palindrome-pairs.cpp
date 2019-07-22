// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
// Example 1:
//
//
//
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]] 
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
//
// Example 2:
//
//
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]] 
// Explanation: The palindromes are ["battab","tabbat"]
//
//
//
//


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //建立一个单词与下标的哈希表，对于每一个单词，先反转其自身，看是否在哈希表中出现过。
        //同时考虑到"lls","s"这种情况，我们遍历比当前单词短的长度，去除可能存在的部分回文子串如"ll"，再找剩余部分的反转是否存在哈希表中
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        set<int> s; //存储字符串的长度
        int len = words.size();
        for(int i = 0; i < len; ++i) {
            m[words[i]] = i;
            s.insert(words[i].size());
        }
        
        for(int i = 0; i < len; ++i) {
            string tmp = words[i];
            int tmp_len = tmp.size();
            reverse(tmp.begin(),tmp.end()); //反转
            
            //反转后的字符串存在且不为自身
            if(m.count(tmp) && m[tmp] != i) {
                ans.push_back({m[tmp] , i});  //符合条件的一组
            }
            
            auto a = s.find(tmp_len);  //找比其长度短的字符串
            for(auto it = s.begin(); it != a; ++it) {
                int cur_len = *it;
                //分为前后两部分两种情况
                if(isPalindrome(tmp, 0, tmp_len-cur_len-1) && m.count(tmp.substr(tmp_len-cur_len))) {
                    ans.push_back({i , m[tmp.substr(tmp_len-cur_len)]});
                }
                
                if(isPalindrome(tmp, cur_len, tmp_len-1) && m.count(tmp.substr(0, cur_len))) {
                    ans.push_back({m[tmp.substr(0, cur_len)], i});
                }
            }
            
        }
        
        return ans;
    }
    
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        
        return true;
    }
};
