// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//
// Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
//
//  
//
// Example 1:
//
//
// Input: [[4,3,8,4],
//         [9,5,1,9],
//         [2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// 438
// 951
// 276
//
// while this one is not:
// 384
// 519
// 762
//
// In total, there is only one magic square inside the given grid.
//
//
// Note:
//
//
// 	1 <= grid.length <= 10
// 	1 <= grid[0].length <= 10
// 	0 <= grid[i][j] <= 15
//
//


class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows<3 || cols<3) return 0;
        int cnts = 0;
        for(int i=0;i<=rows-3;i++){
            for(int j=0;j<=cols-3;j++){
                
                 vector<bool> v (10, false);
                 for (int k = i; k < i + 3; k++) {
                    for (int n = j; n < j + 3; n++) {
                        v[grid[k][n]] = true;
                    }
                 }
                
                int tmp1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int tmp2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                if(tmp1!=tmp2) continue;
                int tmp3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                if(tmp2!=tmp3) continue;
                int tmp4 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                if(tmp3!=tmp4) continue;
                int tmp5 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                if(tmp4!=tmp5) continue;
                int tmp6 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                if(tmp5!=tmp6) continue;
                int tmp7 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                if(tmp6!=tmp7) continue;
                int tmp8 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
                if(tmp7!=tmp8) continue;
                //cout<<tmp1<<tmp2<<tmp3<<tmp4<<tmp5<<tmp6<<tmp7<<tmp8<<endl;
                bool all_int = true;
                 for (int i = 1; i <= 9; i++) {
                    if (!v[i]) {
                        all_int=false;
                        break;
                    }
                }
                if(all_int) cnts++;
            }
        }
        return cnts;
    }
};
