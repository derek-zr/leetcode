// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
//
// Example:
//
//
// Input: matrix = [[1,0,1],[0,-2,3]], k = 2
// Output: 2 
// Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is 2,
//              and 2 is the max number no larger than k (k = 2).
//
// Note:
//
//
// 	The rectangle inside the matrix must have an area > 0.
// 	What if the number of rows is much larger than the number of columns?
//


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        if(matrix.empty() || matrix[0].empty()) return 0;
        int ans = INT_MIN, rows = matrix.size(), cols = matrix[0].size();
        
        /*将二维数组按照行列折叠到一维数组中，再对一维数组求前缀和数组的lower_bound
        general time complexity is O[min(m,n)^2 * max(m,n) * log(max(m,n))], space O(max(m, n)).
        根据时间复杂度和题目中条件：行数远大于列数。我们按照列进行压缩
        */
        for(int c = 0; c < cols; ++c) {
            vector<int> sum(rows , 0);
            for(int i = c; i < cols; ++i) {
                for(int r = 0; r < rows; ++r) {
                    sum[r] += matrix[r][i];   //每一行的和
                }
                int cur_sum = 0;
                set<int> s;  //压入前缀和
                s.insert(0);  //压入0，因为可能出现cur_sum == k的情况
                for(auto a : sum) {
                    cur_sum += a;
                    auto it = s.lower_bound(cur_sum - k);  //cur_sum - *it <= k
                    if (it != s.end()) ans = max(ans,cur_sum-*it);
                    s.insert(cur_sum);   //插入当前计算到的前缀和
                }
            }
        }
        return ans;
        
        /*仿照前缀和的思路，sum(i,j)表示从原点到(i,j)的所有数的和
        vector<vector<int>> preSum(rows,vector<int>(cols,0));
        
        for(int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                preSum[i][j] = matrix[i][j];
                //计算前序和
                if(i > 0) preSum[i][j] += preSum[i-1][j]; 
                if(j > 0) preSum[i][j] += preSum[i][j-1];
                if(i > 0 && j > 0) preSum[i][j] -= preSum[i-1][j-1];  //去除掉重复加的部分
                
                //开始找可能的值
                for(int r = 0; r <= i; ++r) {
                    for (int c = 0; c <= j; ++c) {
                        //计算可能的差值
                        int tmp = preSum[i][j];
                        if(r > 0) tmp -= preSum[r-1][j];
                        if(c > 0) tmp -= preSum[i][c-1];
                        if(r > 0 && c > 0) tmp += preSum[r-1][c-1];
                        //cout<<tmp<<k<<endl;
                        if(tmp <= k) ans = max(ans,tmp);
                    }
                }
            }
        }
        return ans;
        */
    }
};
