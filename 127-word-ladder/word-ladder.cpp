// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time.
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return 0 if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        if(len==0) return 0;
        vector<char> alphas;
        for(int i=0;i<26;i++) alphas.push_back('a'+i);
        unordered_set<string> lists(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        int changes=1;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                string tmp = q.front();
                q.pop();
                if(tmp==endWord) return changes;
                for(int j=0;j<tmp.size();j++){
                    char tmp_change = tmp[j];
                    for(char alpha:alphas){
                        tmp[j] = alpha;
                        if(lists.count(tmp) && !visited.count(tmp)){
                            visited.insert(tmp);
                            q.push(tmp);
                        }
                    }
                    tmp[j] = tmp_change;
                }
            }
            
            changes++;
        }
        
        return 0;
    }
};
