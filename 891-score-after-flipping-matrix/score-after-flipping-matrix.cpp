// We have a two dimensional matrix A where each value is 0 or 1.
//
// A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.
//
// After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.
//
// Return the highest possible score.
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
// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation:
// Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//
//  
//
// Note:
//
//
// 	1 <= A.length <= 20
// 	1 <= A[0].length <= 20
// 	A[i][j] is 0 or 1.
//
//
//


class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
    //首先进行行变换，将第一列全部变为1（因为最大的一定具有这个特征）
    //其次进行列变换，每一列中0和1个数较大的那个数就是最终最大的数对应的该列中1的个数（0和1可以互相转换，所以一定往1多的方向变换）
        int rows=A.size();
        int cols=A[0].size();
        int ans=0;
        ans+=rows*(1<<(cols-1));
        for(int i=0;i<rows;i++){
            if(A[i][0]==0){
                for(int j=0;j<cols;j++){
                    A[i][j]=A[i][j]==0? 1:0;
                }   
            }
        }
        for(int j=1;j<cols;j++){
            int num0=0,num1=0;
            for(int i=0;i<rows;i++){
                if(A[i][j]==0) num0++;
                else num1++;
            }
            ans+=max(num0,num1)*(1<<(cols-j-1));
        }
        return ans;
    }
};
