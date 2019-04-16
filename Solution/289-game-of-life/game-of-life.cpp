// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//
//
// 	Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 	Any live cell with two or three live neighbors lives on to the next generation.
// 	Any live cell with more than three live neighbors dies, as if by over-population..
// 	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
//
// Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
//
// Example:
//
//
// Input: 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// Output: 
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]
//
//
// Follow up:
//
//
// 	Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// 	In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
//
//


class Solution {
public:
    //用状态机编码解决。能够在 in place内解决
    //将各种情况分别编码为1 2 3 4.
    //状态0： 死细胞转为死细胞
    //状态1： 活细胞转为活细胞
    //状态2： 活细胞转为死细胞
    //状态3： 死细胞转为活细胞
    //最后能活下来的即1 3, 所以得到状态后对各点取余即可
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty() || board[0].empty()) return; 
        int rows = board.size();
        int cols = board[0].size();
        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                int cnts = 0;
                for(int k = 0; k < 8; ++k) {
                    int tmpX = i + dx[k];
                    int tmpY = j + dy[k];
                    if(tmpX>=0 && tmpX<rows && tmpY>=0 && tmpY<cols && (board[tmpX][tmpY]==1 || board[tmpX][tmpY]==2)){
                        ++cnts;
                    }
                }
                
                if(board[i][j] && (cnts < 2 || cnts > 3)) board[i][j]=2;
                if(!board[i][j] && cnts==3) board[i][j]=3;
            }
        }
        
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                board[i][j] %= 2;  //对2取余
            }
        }
    }
};
