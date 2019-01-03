// On a N * N grid, we place some 1 * 1 * 1 cubes.
//
// Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
//
// Return the total surface area of the resulting shapes.
//
//  
//
//
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: [[2]]
// Output: 10
//
//
//
// Example 2:
//
//
// Input: [[1,2],[3,4]]
// Output: 34
//
//
//
// Example 3:
//
//
// Input: [[1,0],[0,2]]
// Output: 16
//
//
//
// Example 4:
//
//
// Input: [[1,1,1],[1,0,1],[1,1,1]]
// Output: 32
//
//
//
// Example 5:
//
//
// Input: [[2,2,2],[2,1,2],[2,2,2]]
// Output: 46
//
//
//  
//
// Note:
//
//
// 	1 <= N <= 50
// 	0 <= grid[i][j] <= 50
//
//
//
//
//
//
//


class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        //对于竖向叠放的cube，surface=6+(i-1)*4
        //对于横向的cube,surface要减去四周的重叠面
        int rows=grid.size();
        int cols=grid[0].size();
        int surface=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]) surface+=6+(grid[i][j]-1)*4;
                if(i+1<rows){int tmp=min(grid[i][j],grid[i+1][j]);surface-=tmp*2;} //减去重叠面*2
                if(j+1<cols){int tmp=min(grid[i][j],grid[i][j+1]);surface-=tmp*2;}
            }
        }
        return surface;
    }
};
