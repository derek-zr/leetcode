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
    void solveSudoku(vector<vector<char> > &board) {
        //dfs题
        if (board.empty()) return;
        solveSudokuDFS(board, 0, 0);
    }
    bool solveSudokuDFS(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return solveSudokuDFS(board, i + 1, 0);
        if (board[i][j] == '.') {  //尝试填数字
            for (int k = 1; k <= 9; ++k) {
                board[i][j] = (char)(k + '0');
                if (isValid(board, i , j)) {
                    if (solveSudokuDFS(board, i, j + 1)) return true; //填的数字有效，则继续向下dfs填
                }
                board[i][j] = '.';  //不符合则恢复到原来状态
            }
        } else {
            return solveSudokuDFS(board, i, j + 1);
        }
        return false;
    }
    bool isValid(vector<vector<char> > &board, int i, int j) {
        for (int col = 0; col < 9; ++col) {
            if (col != j && board[i][j] == board[i][col]) return false;
        }
        for (int row = 0; row < 9; ++row) {
            if (row != i && board[i][j] == board[row][j]) return false;
        }
        //找到ij所在的3x3方阵
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
                if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
            }
        }
        return true;
    }
};
