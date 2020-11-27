// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
//
//  
// Example 1:
//
//
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//
//
// Example 2:
//
//
// Input: n = 1
// Output: [["Q"]]
//
//
//  
// Constraints:
//
//
// 	1 <= n <= 9
//
//


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp(n,string(n,'.'));
        dfs(ans,tmp,0);
        return ans;
    }
    
    void dfs(vector<vector<string>> &ans,vector<string> &tmp,int row) {
        int n = tmp.size();
        if(row == n) {ans.push_back(tmp);return;}
        for(int col = 0; col < n; ++col) {
            if(isValid(tmp,row,col)) {
                tmp[row][col] = 'Q';
                dfs(ans,tmp,row+1);
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
