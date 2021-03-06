// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//
// 	Each row must contain the digits 1-9 without repetition.
// 	Each column must contain the digits 1-9 without repetition.
// 	Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//
// Note:
//
//
// 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// 	Only the filled cells need to be validated according to the mentioned rules.
//
//
//  
// Example 1:
//
//
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
//
//
// Example 2:
//
//
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//
//  
// Constraints:
//
//
// 	board.length == 9
// 	board[i].length == 9
// 	board[i][j] is a digit or '.'.
//
//


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = rows;
        //check rows
        for(int i=0;i<rows;i++){
            set<int> s;
            for(int j=0;j<cols;j++){
                if(board[i][j]=='.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        
        //check cols
        for(int i=0;i<cols;i++){
            set<int> s;
            for(int j=0;j<rows;j++){
                if(board[j][i]=='.') continue;
                if(s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        }
    
        //check 3x3
        for(int i=0;i<=rows-3;i+=3){
            for(int j=0;j<=cols-3;j+=3){
                set<int> s;
                for(int k=0;k<3;k++){
                    for(int m=0;m<3;m++){
                        if(board[i+k][j+m]=='.') continue;
                        if(s.count(board[i+k][j+m])) return false;
                        s.insert(board[i+k][j+m]);
                    }
                }    
            }
        }
        
        return true;
    }
};
