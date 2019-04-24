// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
//
//
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//
// Example:
//
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
//
// return 13.
//
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ n2.


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //第一种方法用heap做，把matrix元素读进一个最大堆中即可。不再赘述。
        //第二种方法是把要找的目标值转换为一个二分查找问题，把数组中最小和最大的值作为left和right，计算数组中小于mid的数目，与k进行比较，进行二分。当left和right相等时，即要找的ksmallest
        int rows = matrix.size();
        int cols = matrix[0].size(); 
        int left = matrix[0][0],right = matrix[rows-1][cols-1];
        
        while(left < right) {
            int mid = (right-left)/2 + left;
            int less_cnt = 0;
            //这里我们可以使用一种更高效的计算less_cnt的方法。之前做过一道在类似性质的数组中找某个值的题目，这里也可以用相同的方法。从左下角的数开始遍历，计算需要的值。
            less_cnt = cnt(matrix,mid);
            /*
            for(int i = 0; i < rows; ++i) {
                less_cnt += (upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin());
            }
            */
            if(less_cnt < k) left = mid+1;
            else right = mid;
        }
        return right;
    }
    
    int cnt(vector<vector<int>>& matrix, int mid) {
        int row = matrix.size()-1, col = 0;
        int len = matrix[0].size();
        int cnts = 0;
        while(row >= 0 && col < len) {
            if(matrix[row][col] <= mid) {
                ++col; //列向后移，因为后面列的值肯定更大
                cnts += row+1 ; //当前整列的值一定都小于target，直接加上
            }
            else --row; //否则行向上移，因为上面行的值更小
        }
        
        return cnts;
    }
};
