// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted in ascending from left to right.
// 	Integers in each column are sorted in ascending from top to bottom.
//
//
// Example:
//
// Consider the following matrix:
//
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
//
//
// Given target = 5, return true.
//
// Given target = 20, return false.
//


class Solution {
public:
    //可以从左下角的点或者右上角的点开始查找
    //对于左下角的点，向右则数增大，向上则数减小
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int bottom = matrix.size()-1;
        int left = 0;
        
        while(1) {
            //cout<<left<<bottom<<endl;
            if(target > matrix[bottom][left]) ++left;
            else if(target < matrix[bottom][left]) --bottom;
            else return true;
            //超过边界跳出循环
            if(left >= matrix[0].size() || bottom < 0) break;
        }
        
        return false;
    }
};
