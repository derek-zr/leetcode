// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//
// 	Each of the digits 1-9 must occur exactly once in each row.
// 	Each of the digits 1-9 must occur exactly once in each column.
// 	Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
//
// The '.' character indicates empty cells.
//
//  
// Example 1:
//
//
// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:
//
//
//
//
//  
// Constraints:
//
//
// 	board.length == 9
// 	board[i].length == 9
// 	board[i][j] is a digit or '.'.
// 	It is guaranteed that the input board has only one solution.
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
