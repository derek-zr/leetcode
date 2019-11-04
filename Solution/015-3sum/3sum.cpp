// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //双指针法遍历查找，利用sort后的有序特性剪枝
        //这道题用hashmap那种做法，会导致不好去除重复值，利用set去除会TLE
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        sort(nums.begin(), nums.end());
        //剪枝
        //if(nums.back() < 0 || nums[0] > 0) return ans;   //总和为0.则必然要有正有负
        for(int a = 0; a < (int)nums.size()-2; ++a) {  //这里必须要做类型转换，size_t-2可能会变成负数，会报heapoverflow的错
            if(nums[a] > 0) break;  //只找负数，剪枝
            //删除重复的
            if(a > 0 && nums[a] == nums[a-1]) continue;
            //开始遍历
            int target = -nums[a], b = a+1, c = nums.size()-1;
            while(b < c) {
                //cout<<b<<c<<endl;
                //找到了满足条件的
                if(nums[b] + nums[c] == target) {
                    ans.push_back({nums[a], nums[b], nums[c]});
                    //去除重复
                    while(b < c && nums[b] == nums[b+1]) ++b;
                    while(b < c && nums[c] == nums[c-1]) --c;
                    ++b;
                    --c;
                }
                else if(nums[b]+nums[c] < target) ++b;
                else --c;
            }
        }
        return ans;
    }
};
