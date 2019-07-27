// Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//
// Note:
// The array size can be very large. Solution that uses too much extra space will not pass the judge.
//
// Example:
//
//
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
//
// // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);
//
// // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);
//
//


class Solution {
public:
    //水池采样
    //从n个的集合中抽取k个样本
    /*
    從S中抽取首k項放入「水塘」中
    對於每一個S[j]項（j ≥ k）：
    隨機產生一個範圍從0到j的整數r
    若 r < k 則把水塘中的第r項換成S[j]項
    */
    Solution(vector<int>& nums) : data(nums) {}
    
    int pick(int target) {
        int cnt = 0, ans = -1;
        for(int i = 0; i < data.size(); ++i) {
            if(data[i] != target) continue;
            ++cnt;
            if(rand() % cnt == 0) ans = i;    //rand()%1一定为0，即第一个遇到的值一定会被赋值给ans
        }
        return ans;
    }

private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
