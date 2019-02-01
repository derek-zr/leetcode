// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
//
//
// Example :
// Input: 
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
//
//
// Note:
//
//
// 	All words in words and S will only consists of lowercase letters.
// 	The length of S will be in the range of [1, 50000].
// 	The length of words will be in the range of [1, 5000].
// 	The length of words[i] will be in the range of [1, 50].
//
//


class Solution {
public:
    //记录符合条件和不符合条件的单词，避免重复计算
    int numMatchingSubseq(string S, vector<string>& words) {
        int ans=0;
        unordered_set<string> sub,nosub;
        for(auto word : words){
            if(sub.count(word)) {ans++;continue;}
            else if(nosub.count(word)) continue;
            else{
                int len1=word.size();
                int len2=S.size();
                int i=0,j=0;
                while(i<len1 && j<len2){
                    if(word[i]==S[j]) i++;
                    j++;
                }
        
                if(i==len1) {ans++;sub.insert(word);}
                else nosub.insert(word);
            }
        }
        
        return ans;
    }
};
