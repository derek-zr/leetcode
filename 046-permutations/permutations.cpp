// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtrack(ans,tmp,nums);
        return ans;
    }
    
    void backtrack(vector<vector<int>> &ans,vector<int> tmp,vector<int> nums){
        if(tmp.size()==nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(tmp.begin(),tmp.end(),nums[i])!=tmp.end()) continue;
            tmp.push_back(nums[i]);
            backtrack(ans,tmp,nums);
            tmp.pop_back();
        }
    }
};
