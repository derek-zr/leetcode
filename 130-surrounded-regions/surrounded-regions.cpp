// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// Example:
//
//
// X X X X
// X O O X
// X X O X
// X O X X
//
//
// After running your function, the board should be:
//
//
// X X X X
// X X X X
// X X X X
// X O X X
//
//
// Explanation:
//
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
//


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows==0) return;
        int cols = board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0||j==0||i==rows-1||j==cols-1){
                    dfs(board,i,j);
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='@') board[i][j]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board,int i, int j){
        if(board[i][j]=='O'){
            board[i][j] = '@';
            if(i+1<board.size() && board[i+1][j]=='O') dfs(board,i+1,j);
            if(i-1>=0 && board[i-1][j]=='O') dfs(board,i-1,j);
            if(j+1<board[0].size() && board[i][j+1]=='O') dfs(board,i,j+1);
            if(j-1>=0 && board[i][j-1]=='O') dfs(board,i,j-1);
        }
        
        return;
    }
};
