// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//
// 	Each of the digits 1-9 must occur exactly once in each row.
// 	Each of the digits 1-9 must occur exactly once in each column.
// 	Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
//
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
//
// 	The given board contain only digits 1-9 and the character '.'.
// 	You may assume that the given Sudoku puzzle will have a single unique solution.
// 	The given board size is always 9x9.
//
//


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //dfs题，不断尝试填入新的数字，并检测是否有效
        if(board.empty()) return;
        helper(board, 0 , 0);   //传递行列信息
        return;
    }
    
    bool helper(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        //新的一行
        if (col >= 9) return helper(board, row+1, 0);
        if (board[row][col] != '.') return helper(board, row, col+1);
        //需要填充，尝试并检测是否有效
        for(char c = '1'; c <= '9'; ++c) {
            if (!isValid(board, row, col, c)) continue; //填充的c已经在当前的行列及3*3方块中出现过
            board[row][col] = c;
            if(helper(board, row, col+1)) return true;  //dfs
            board[row][col] = '.';
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        //检查行
        for(int j =0; j < 9; ++j) {
            if (board[row][j] == c) return false;
        } 
        //检查列
        for(int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
        }
        //检查方格
        int cur_row = row / 3 * 3;
        int cur_col = col / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[cur_row + i][cur_col + j] == c) return false;
            }
        }
        return true;
    }
};
