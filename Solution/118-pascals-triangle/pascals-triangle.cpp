// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==0) return ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> tmp(i+1,1);
            for(int j=1;j<i;j++){
                tmp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
