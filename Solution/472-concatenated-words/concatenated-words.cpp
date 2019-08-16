// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
//
// Example:
//
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
//
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//
//
//
// Note:
//
// The number of elements of the given array will not exceed 10,000 
// The length sum of elements in the given array will not exceed 600,000. 
// All the input string will only include lower case letters.
// The returned elements order does not matter. 
//
//


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //用dict存储所有出现过的单词。随后遍历查找某个词的子串是否出现在dict中
        vector<string> ans;
        unordered_set<string> dict(words.begin(),words.end());
        //遍历
        for(string word : words) {
            if(word.empty()) continue;
            int len = word.size();
            vector<bool> dp(len+1,false);   //dp[i]表示前i个位置的字符串可以拼接得到
            dp[0] = true;
            //遍历查找所有子串
            for(int i = 0; i < len; ++i) {
                if(!dp[i]) continue;
                for(int j = i+1; j <= len; ++j) {
                    if(j - i < len && dict.count(word.substr(i,j-i))) {
                        dp[j] = true;   //dp[i]=true 并且i到j的子串出现在dict中
                    }
                }
                if(dp[len]) {   //已经找到一组子串可拼接成该字符串
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
};
