// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
//
// The distance between two adjacent cells is 1.
//
//  
//
// Example 1: 
//
//
// Input:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]
//
// Output:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]
//
//
// Example 2: 
//
//
// Input:
// [[0,0,0],
//  [0,1,0],
//  [1,1,1]]
//
// Output:
// [[0,0,0],
//  [0,1,0],
//  [1,2,1]]
//
//
//  
//
// Note:
//
//
// 	The number of elements of the given matrix will not exceed 10,000.
// 	There are at least one 0 in the given matrix.
// 	The cells are adjacent in only four directions: up, down, left and right.
//
//


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //先把所有的1替换为INT_MAX，0放进队列。
        //进行BFS，如果队列中点的周围四个点的值均小于当前值加1，则无需更新周围的值。否则将周围点的值更新为当前点值+1，并放进队列。
        queue<pair<int,int>> points;
        int rows=matrix.size(),cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0) points.push({i,j});  //0的点作为最初的起点
                else matrix[i][j]=INT_MAX;
            }
        }
        
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!points.empty()){
            auto start=points.front();
            points.pop();
            int now = matrix[start.first][start.second];
            for(auto dir:dirs){
                int tmp_x = start.first+dir[0];
                int tmp_y = start.second+dir[1];
                if(tmp_x<0||tmp_x>=rows||tmp_y<0||tmp_y>=cols||matrix[tmp_x][tmp_y]<now+1) continue;
                matrix[tmp_x][tmp_y]=now+1;
                points.push({tmp_x,tmp_y});
            }
        }
        
        return matrix;
    }
};
