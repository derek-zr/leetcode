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
        vector<string> ans;
        if(board.empty() || board[0].empty() || words.empty()) return ans;
        Trie t;
        for(string s : words) t.insert(s);
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(t.root->child[board[i][j]-'a']){
                    dfs(ans,board,t.root->child[board[i][j]-'a'],visited,i,j);
                }
            }
        }
        //sort(ans.begin(),ans.end());
        return ans;
    }

private:
    struct TrieNode {
        TrieNode *child[26];
        string str;   //保存叶子节点的字符串值
        TrieNode() :str("") {
            for(auto &a : child) a = NULL;
        }
    };
    
    struct Trie {
        TrieNode * root;
        Trie() : root(new TrieNode()) { };
        
        void insert(string s) {
            TrieNode* tmp = root;
            for(char c : s) {
                int i = c - 'a';
                if(!tmp->child[i]) tmp->child[i] = new TrieNode();
                tmp = tmp->child[i];
            }
            
            tmp->str = s;  //叶子节点保存当前树的值
        }
    };
    
     void dfs(vector<string>& ans,vector<vector<char>>& board,TrieNode *p,vector<vector<bool>> &visited,int i,int j) {
        if(!p->str.empty()) {
            ans.push_back(p->str);
            p->str.clear();   //这里需要清空，因为最终结果同一个word只能出现一次
            //return;        //注意这里不能return，因为words中可能存在一个word是另一个的子串，如bend,benda,这时候如果return的话，则不会继续遍历到benda
        }
        int dirs[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[i][j] = true;
        for(int k = 0; k < 4; ++k) {
            int tmpX = dirs[k][0] + i;
            int tmpY = dirs[k][1] + j;
            if(tmpX >= 0 && tmpX < board.size() && tmpY >= 0 && tmpY < board[0].size() && !visited[tmpX][tmpY] && p->child[board[tmpX][tmpY]-'a']) {
                dfs(ans,board,p->child[board[tmpX][tmpY]-'a'],visited,tmpX,tmpY);
            }
        }
        
        visited[i][j] = false;
        return;
    }
    
};
