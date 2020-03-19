// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
//
//
//  
// Constraints:
//
//
// 	board and word consists only of lowercase and uppercase English letters.
// 	1 <= board.length <= 200
// 	1 <= board[i].length <= 200
// 	1 <= word.length <= 10^3
//
//


class Solution {
public:
    //dfs
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,0));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,word,0,i,j,visited)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word,int index,int i, int j ,vector<vector<bool>>& visited){
        if(index==word.size()) return true;
        int rows = board.size();
        int cols = board[0].size();
        if(i<0 || j<0 || i>=rows || j>=cols || visited[i][j] || board[i][j]!=word[index]) return false;
        
        visited[i][j] = true;
        
        bool valid = dfs(board,word,index+1,i-1,j,visited) || dfs(board,word,index+1,i+1,j,visited) || dfs(board,word,index+1,i,j-1,visited) || dfs(board,word,index+1,i,j+1,visited);
        
        visited[i][j] = false;
        
        return valid;
        
    }
};
