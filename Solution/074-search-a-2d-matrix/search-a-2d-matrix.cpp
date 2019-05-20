// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //将二维数组视为一个排序好的数组，（0，rows*cols）
        //row col -> row*cols+col
        //则二分时下标转换为[mid/cols][mid%cols]
        if(matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(),cols = matrix[0].size();
        int left = 0, right = rows*cols-1;
        //二分查找
        while(left <= right) {
            int mid = left + (right-left)/2;
            int tmp = matrix[mid/cols][mid%cols];
            if(tmp == target) return true;
            else if(tmp > target) right = mid-1;
            else left = mid+1;
        }
        
        return false;
    }
};
