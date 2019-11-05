// Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
//
// Example 1:
//
//
// Input: nums = [1,3], n = 6
// Output: 1 
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
//
// Example 2:
//
//
// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].
//
//
// Example 3:
//
//
// Input: nums = [1,2,2], n = 5
// Output: 0
//


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //这道题很像腾讯暑期实习的机试题，凑硬币和这个的题目要求基本相同
        
        long cur_last = 1;  //表示当前遍历到的数组能够组成的范围为[0,cur_last-1]
        int ans = 0, i = 0;
        //直到当前能够遍历到的范围大于n
        while (cur_last <= n) {
            //能够通过加上nums[i]达到更高的范围
            if(i < nums.size() && nums[i] <= cur_last) {
                cur_last += nums[i++];
            }
            else {
                cur_last += cur_last;  //插入cur_last,因为数组中现有的值都组合不成cur_last
                ++ans;
            }
        }
        return ans;
    }
};
