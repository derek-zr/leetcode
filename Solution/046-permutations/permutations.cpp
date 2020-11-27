// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//
//  
// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:
// Input: nums = [1]
// Output: [[1]]
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 6
// 	-10 <= nums[i] <= 10
// 	All the integers of nums are unique.
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        /*
        vector<int> tmp;
        helper(ans,tmp,nums);
        */
        
        //不需要tmp数组的方法：递归交换两个位置，最终得到所有可能的排列
        helper(ans, nums, 0);
        return ans;
    }
    
    void helper(vector<vector<int>> &ans, vector<int>& nums, int start) {
        if(start >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            //继续交换下一个位置
            helper(ans, nums, start+1);
            swap(nums[start], nums[i]);            
        }
    }
    
    /*
    void helper(vector<vector<int>> &ans,vector<int> tmp,vector<int> nums){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end()) continue;
            tmp.push_back(nums[i]);
            helper(ans,tmp,nums);
            tmp.pop_back();
        }
    }
    */
};
