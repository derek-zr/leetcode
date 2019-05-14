// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//
// Example:
//
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
//
//


class Solution {
public:
    int totalNQueens(int n) {
        int cnts = 0;
        vector<string> tmp(n,string(n,'.'));
        dfs(cnts,tmp,0);
        return cnts;
    }

    void dfs(int &cnts,vector<string> &tmp,int row) {
        int n = tmp.size();
        if(row == n) {++cnts;return;}
        for(int col = 0; col < n; ++col) {
            if(isValid(tmp,row,col)) {
                tmp[row][col] = 'Q';
                dfs(cnts,tmp,row+1);
                tmp[row][col] = '.';
            }
        }
    }

     bool isValid(vector<string> &tmp,int row,int col) {
         for(int i = 0; i < row; ++i) {
             if(tmp[i][col]=='Q') return false;
         }
         //正对角线上部
         for(int i = row-1,j = col-1; i >= 0 && j >= 0; --j,--i) {
             if(tmp[i][j] == 'Q') return false;
         }
         //反对角线/上部
         for(int i = row-1,j = col+1; i >= 0 && j < tmp.size();--i,++j) {
             if(tmp[i][j] == 'Q') return false;
         }
         return true;
     }

};
