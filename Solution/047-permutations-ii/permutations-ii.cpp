// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
//
//  
// Example 1:
//
//
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
//
//
// Example 2:
//
//
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//
//  
// Constraints:
//
//
// 	1 <= nums.length <= 8
// 	-10 <= nums[i] <= 10
//
//


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(nums, 0, res);
        return res;
        
        /*用visited数组去除重复情况
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        vector<int> tmp,visited(nums.size(),0);
        sort(nums.begin(),nums.end());  //让相同的数排列到一起
        dfs(nums,ans,tmp,visited,0);
        return ans;
        */
    }
    
    void permute(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start >= nums.size()) res.push_back(nums);
        for (int i = start; i < nums.size(); ++i) {
            int j = i - 1;
            while (j >= start && nums[j] != nums[i]) --j;
            if (j != start - 1) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
    
    void dfs(vector<int> &nums,vector<vector<int>> &ans,vector<int> &tmp,vector<int> &visited,int level) {
        int len = nums.size();
        if(level >= len) {ans.push_back(tmp);return;}
        for(int i = 0; i < len; ++i) {
            if(visited[i]==1) continue; 
            if(i>0 && nums[i]==nums[i-1] && visited[i-1]==1) continue; //去除重复的排列
            visited[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums,ans,tmp,visited,level+1);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
};
