// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
//
// Formally the function should:
//
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
//
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
//
//
// Example 1:
//
//
// Input: [1,2,3,4,5]
// Output: true
//
//
//
// Example 2:
//
//
// Input: [5,4,3,2,1]
// Output: false
//
//
//


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        //第二种方法，O(n)时间复杂度和O(1)空间复杂度
        //用两个值记录，保证num1和num2的递增关系，在向后遍历的过程中，不断更新num1和num2，如果遍历到了大于num2的值，则说明此时num1，num2，now构成了一组递增三元组
        int len = nums.size();
        if(len < 3) return false;
        int num1 = INT_MAX, num2 = INT_MAX;
        
        for(int i = 0; i < len; ++i) {
            if(num1 >= nums[i]) num1 = nums[i]; //num1尽可能的小
            else if(num2 >= nums[i]) num2 = nums[i]; //num1<nums[i]<num2
            else return true;  //num1<num2<nums[i] 符合条件的三元组
        }
        
        return false;
        
        
        /*
        //第一种方法，用两个数组：pre代表0-i内最小的数字，after代表i-n内最大的数字
        //得到两个数组后，如果存在某个i，使得pre[i]<nums[i]<after[i]，则是一个递增三元组
        int len = nums.size();
        if(len<3) return false;
        vector<int> pre(len,nums[0]);
        vector<int> after(len,nums[len-1]);
        
        for(int i = 1; i < len; ++i) {
            pre[i] = min(nums[i],pre[i-1]);
        }
        for(int i = len-2; i >= 0; --i) {
            after[i] = max(after[i+1],nums[i]);
        }
        
        for(int i = 0; i < len; ++i) {
            if(pre[i] < nums[i] && nums[i] < after[i]) return true;
        }
        
        return false;*/
    }
};
