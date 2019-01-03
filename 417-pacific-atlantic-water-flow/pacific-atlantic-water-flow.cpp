// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//
// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
// Note:
//
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
//
//
// Example:
//
// Given the following 5x5 matrix:
//
//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic
//
// Return:
//
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
//
//


class Solution {
public:
    //分别从边缘点向中间dfs，若atlan和paci都能访问到，则这个点满足条件
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<pair<int,int>> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> atlan(row,vector<bool>(col,false));
        vector<vector<bool>> paci(row,vector<bool>(col,false));
        
        //边缘列dfs
        for(int i=0;i<row;i++){
            dfs(matrix,paci,INT_MIN,i,0);
            dfs(matrix,atlan,INT_MIN,i,col-1);
        }
        //边缘行dfs
        for(int j=0;j<col;j++){
            dfs(matrix,paci,INT_MIN,0,j);
            dfs(matrix,atlan,INT_MIN,row-1,j);
        }
        //altan和paci中均为true的坐标
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(atlan[i][j] && paci[i][j]) ans.push_back({i,j});
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>>& visited,int height,int i,int j){
        int row = matrix.size();
        int col = matrix[0].size();
        if(i<0 || i>=row || j<0 || j>=col || visited[i][j] ||matrix[i][j]<height) return;
        visited[i][j] = true;
        dfs(matrix,visited,matrix[i][j],i-1,j);
        dfs(matrix,visited,matrix[i][j],i+1,j);
        dfs(matrix,visited,matrix[i][j],i,j-1);
        dfs(matrix,visited,matrix[i][j],i,j+1);
    }
    
};
