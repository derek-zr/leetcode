// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
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
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
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
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //bfs
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        vector<string> tmp;
        tmp.push_back(beginWord);
        queue<vector<string>> q;
        q.push(tmp);
        int level = 1,minLevel = INT_MAX;
        unordered_set<string> visited;
        
        while(!q.empty()) {
            vector<string> cur = q.front();
            q.pop();
            if(cur.size() > level) {
                for(string s : visited) dict.erase(s); //已经出现过的不能再出现且后续情况也不可能出现，因为一旦当前遍历到该词即意味着bfs找到了到达该词的最短路径，后面的其他情况不可能比这种情况更短
                visited.clear();   //清除当前的已访问节点
                level = cur.size();  //更新当前遍历到的level数目，即路径长度
                if(level > minLevel) break;  //说明后面的路径长度均大于最短长度，不可能出现在结果列表中
            }
            string preStr = cur.back();  //当前遍历到词
            int strLen = preStr.size();
            for(int i = 0; i < strLen; ++i) {
                string changeStr = preStr; //每次都初始化为原始值
                for(char c = 'a'; c <= 'z'; ++c) {
                    changeStr[i] = c;
                    if(!dict.count(changeStr)) continue;  //不在字典中
                    visited.insert(changeStr);
                    vector<string> nextWord = cur;
                    nextWord.push_back(changeStr);  //下一个可能的路径
                    if(changeStr == endWord) {
                        ans.push_back(nextWord);
                        minLevel = level;  //找到了最短的符合条件的路径
                    }
                    else q.push(nextWord);
                }
            }
        }
        return ans;
    }
};
