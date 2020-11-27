// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//
// Return true if there is a 132 pattern in nums, otherwise, return false.
//
// Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?
//
//  
// Example 1:
//
//
// Input: nums = [1,2,3,4]
// Output: false
// Explanation: There is no 132 pattern in the sequence.
//
//
// Example 2:
//
//
// Input: nums = [3,1,4,2]
// Output: true
// Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//
//
// Example 3:
//
//
// Input: nums = [-1,3,2,0]
// Output: true
// Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
//
//
//  
// Constraints:
//
//
// 	n == nums.length
// 	1 <= n <= 104
// 	-109 <= nums[i] <= 109
//
//


class Solution {
public:
    //找当前最优的(s2,s3)对，实时更新s3的值，栈中存放所有满足的s2的值
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len<3) return false;
        int s3 = INT_MIN;
        stack<int> s;
        for(int i=len-1;i>=0;i--){
            if(nums[i]<s3) return true;
            while(!s.empty() && nums[i]>s.top()){
                s3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        
        return false;
    }
};
