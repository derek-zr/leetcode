// Given a 2D board and a list of words from the dictionary, find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//  
//
// Example:
//
//
// Input: 
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]
//
// Output: ["eat","oath"]
//
//
//  
//
// Note:
//
//
// 	All inputs are consist of lowercase letters a-z.
// 	The values of words are distinct.
//
//


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //典型的dfs题，但问题在于如何剪枝。对于字符串，很容易想到Trie树，判断前缀是否相等，及时剪枝
        //但这里的Trie树需要做一些变化，为了方便存储结果，最后叶子节点的IsWordEnd被换成了当前路径的str
        vector<string> ans;
        if (board.empty() || board[0].empty() || words.empty()) return ans;
        //辅助数据结构
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        //Trie树
        Trie t;
        for (string word : words) t.insert(word);
        
        //开始遍历
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                //根据第一个字符剪枝
                if (t.root->child[board[i][j]-'a']) {
                    dfs(ans, board, t.root->child[board[i][j]-'a'], visited, i, j);
                }
            }
        }
        return ans;
    }

private:
    struct TrieNode {
        TrieNode * child[26];
        string str;
        TrieNode() : str("") {
            for (auto &c :child) c = NULL;
        }
    };
    
    struct Trie {
        TrieNode* root;
        Trie() : root(new TrieNode()) { }
        //插入函数
        void insert(string s) {
            TrieNode* cur = root;
            for (char c : s) {
                if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }
            cur->str = s;   //叶子节点
        }
    };
    
    void dfs(vector<string> &ans, vector<vector<char>>& board, TrieNode* p, vector<vector<int>> &visited, int i, int j) {
        if (!p->str.empty()) {
            ans.push_back(p->str);
            p->str.clear();    //清空叶子节点，避免再次存入结果中
            //注意这里与一般的dfs不同，不需要返回。eg. app appa 还需要继续找叶子节点的叶子节点，是否有新的word
        }
        int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[i][j] = true;
        
        for (int k = 0; k < 4; ++k) {
            int curX = i + dirs[k][0];
            int curY = j + dirs[k][1];
            if (curX >= 0 && curX < board.size() && curY >= 0 && curY < board[0].size() && !visited[curX][curY] && p->child[board[curX][curY]-'a']) {
                dfs(ans, board, p->child[board[curX][curY]-'a'], visited, curX, curY);
            }
        }
        visited[i][j] = false;
        return;
    }
    
};
