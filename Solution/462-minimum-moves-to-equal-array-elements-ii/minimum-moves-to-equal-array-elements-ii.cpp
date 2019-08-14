// Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
//
// You may assume the array's length is at most 10,000.
//
// Example:
//
// Input:
// [1,2,3]
//
// Output:
// 2
//
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
//
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
//
//


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //可以举例看出：排序后的数组中位数即为最优解
        //找中位数
        /*
        sort(nums.begin(),nums.end());
        int ans = 0 , mid = nums[nums.size()/2];
        */
        //不需要完全排序，即不需要nlogn的复杂度。
        //用nth_element函数，实现O(n)的复杂度
        /*
        nth_element 是部分排序算法，它重排 [first, last) 中元素，使得：
        nth 所指向的元素被更改为假如 [first, last) 已排序则该位置会出现的元素。
        这个新的 nth 元素前的所有元素小于或等于新的 nth 元素后的所有元素。
        */
        int ans = 0, mid = nums.size()/2;
        nth_element(nums.begin(),nums.begin()+mid,nums.end());
        for(int num : nums) ans += abs(num-nums[mid]);
        return ans;
    }
};
