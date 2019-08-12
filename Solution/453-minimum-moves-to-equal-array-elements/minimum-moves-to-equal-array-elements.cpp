// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
//
// Example:
//
// Input:
// [1,2,3]
//
// Output:
// 3
//
// Explanation:
// Only three moves are needed (remember each move increments two elements):
//
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
//
//


class Solution {
public:
    int minMoves(vector<int>& nums) {
        //把n-1个元素加1，相当于每次把一个元素减1。
        //为了得到各元素相等，即最终数组元素均等于当前数组中的最小值
        //moves = sum(nums)-len*min_element
        //用0L防止溢出
        return accumulate(nums.begin(),nums.end(),0L)-nums.size()* *(min_element(nums.begin(),nums.end()));
    }
};
