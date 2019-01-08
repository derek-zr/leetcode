// You have a list of words and a pattern, and you want to know which words in words matches the pattern.
//
// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
//
// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)
//
// Return a list of the words in words that match the given pattern. 
//
// You may return the answer in any order.
//
//  
//
//
// Example 1:
//
//
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.
//
//  
//
// Note:
//
//
// 	1 <= words.length <= 50
// 	1 <= pattern.length = words[i].length <= 20
//
//
//


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len=pattern.size();
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(words[i].size()!=len) break;
            map<char,char> px;
            map<char,char> py;
            string changestr="";
            for(int j=0;j<len;j++){
                if(px.find(pattern[j])==px.end()&&py.find(words[i][j])==py.end()) 
                    {px.insert(pair<char,char>(pattern[j],words[i][j]));
                     py.insert(pair<char,char>(words[i][j],pattern[j]));
                     changestr+=words[i][j];}
                else changestr+=px[pattern[j]];
            }
            if(changestr==words[i]) ans.push_back(words[i]);
        }
        return ans;
    }
};
