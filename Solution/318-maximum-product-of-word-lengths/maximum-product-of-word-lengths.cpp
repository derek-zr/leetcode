// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
// Example 1:
//
//
// Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16 
// Explanation: The two words can be "abcw", "xtfn".
//
// Example 2:
//
//
// Input: ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4 
// Explanation: The two words can be "ab", "cd".
//
// Example 3:
//
//
// Input: ["a","aa","aaa","aaaa"]
// Output: 0 
// Explanation: No such pair of words.
//
//


class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        //用bit表示某位置上字母是否出现
        int len = words.size();
        vector<int> mask(len,0);
        
        //得到各字符串的mask
        for(int i = 0; i < len; ++i) {
            for(char c : words[i]) mask[i] |= (1 << (c-'a'));
            
            //遍历之前的字符串，看是否符合条件
            for (int j = 0; j < i; ++j) {
                if(!(mask[i] & mask[j])) {
                    int tmp = words[i].size()*words[j].size();
                    ans = max(ans, tmp);
                }
            }
        }
        
        return ans;
    }
};
