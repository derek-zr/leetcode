// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()) return ans;
        int up=0,bot=matrix.size()-1;
        int left=0, right=matrix[0].size()-1;
        
        while(up<=bot && left<=right) {
            for(int i=left;i<=right;++i) ans.push_back(matrix[up][i]);
            for(int i=up+1;i<=bot;++i) ans.push_back(matrix[i][right]);
            if(up<bot && left<right){
                for(int i=right-1;i>left;--i) ans.push_back(matrix[bot][i]);
                for(int i=bot;i>up;--i) ans.push_back(matrix[i][left]);
            }
            up++;
            bot--;
            left++;
            right--;
        }
        
        return ans;
    }
};
