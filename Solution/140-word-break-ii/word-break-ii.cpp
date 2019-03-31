// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
//
// Example 2:
//
//
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []
//


class Solution {
public:
     vector<string> wordBreak(string s, vector<string>& wordDict) {
        //dfs with memo
         unordered_map<string,vector<string>> m ; //用于记录之前已经出现过的s所对应的情况
         return dfs(s,wordDict,m);
    }
    
    vector<string> dfs(string s,vector<string>& wordDict,unordered_map<string,vector<string>>& m){
        if(m.count(s)) return m[s];
        if(s.empty()) return {""};  //证明已经到了s的末尾，一种情况已经遍历完成。返回一个空字符串，便于去除最后的空格
        vector<string> ans;
        for(string word : wordDict){
            if(s.substr(0,word.size()) != word) continue;
            vector<string> tmp = dfs(s.substr(word.size()),wordDict,m);
            for(string t : tmp){
                ans.push_back(word + (t.empty() ? "" : " ") + t);
            }
        }
        
        m[s] = ans;
        return ans;
    }
    /*
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        //dfs TLE
        vector<string> ans;
        string tmp;
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        dfs(s,dict,ans,tmp,0);
        return ans;
    }
    
    void dfs(string& s,unordered_set<string>& dict,vector<string>& ans,string& tmp,int start){
        if(start==s.size()) {tmp=tmp.substr(0,tmp.size()-1);ans.push_back(tmp);return;} //这里要去除最后的一个空格
        for(int i = start; i < s.size(); ++i){
            if(dict.count(s.substr(start,i-start+1))){
                int length = tmp.size();
                tmp = tmp + s.substr(start,i-start+1) + ' ';
                dfs(s,dict,ans,tmp,i+1);
                tmp = tmp.substr(0,length);
            }
        }
    }
    */
};
