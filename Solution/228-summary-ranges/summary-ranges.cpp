// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
//
// Input:  [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
// Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
//
//
// Example 2:
//
//
// Input:  [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
// Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
//
//


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty()) return ans;
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(i == len-1) {ans.push_back(to_string(nums[i]));continue;}
            int j = i+1;
            if(nums[j] != (nums[i]+1)) {ans.push_back(to_string(nums[i]));continue;}
            while(j < len && nums[j] == (nums[j-1]+1)) ++j;
            string tmp = to_string(nums[i])+"->"+to_string(nums[j-1]);
            ans.push_back(tmp);
            i = j-1;
        }
        return ans;
    }
};
