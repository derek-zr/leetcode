// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
//
// Example 1:
//
//
// Input: 
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output: 
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
//
//
// Example 2:
//
//
// Input: 
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output: 
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
//
//
// Follow up:
//
//
// 	A straight forward solution using O(mn) space is probably a bad idea.
// 	A simple improvement uses O(m + n) space, but still not the best solution.
// 	Could you devise a constant space solution?
//
//


class Solution {
public:
    //用每一排和每一列的第一个标识是否存在0
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool first_col = false;   //标识第一列是否存在0
        
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0) first_col = true;
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0; //根据行列标识置零
            }
        }
        
        if(matrix[0][0]==0){
            for(int j=0;j<cols;j++){
                matrix[0][j]=0;
            }
        }
        
        if(first_col){
            for(int i=0;i<rows;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
