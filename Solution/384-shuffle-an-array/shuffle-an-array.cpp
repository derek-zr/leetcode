// Shuffle a set of numbers without duplicates.
//
//
// Example:
//
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();
//
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();
//
//


class Solution {
public:
    //参考水塘抽样的思想
    //遍历数组，在每个位置上产生一个随机数，与当前位置的数互换
    Solution(vector<int> nums) :data(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = data;
        for(int i=0;i<ans.size();i++){
            int tmp = i + rand()%(ans.size()-i);   //这里需要保证被swap过的位置不再被swap,产生 i到ans.size()间的随机数
            swap(ans[i],ans[tmp]);
        }
        return ans;
    }

private:
    vector<int> data;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
