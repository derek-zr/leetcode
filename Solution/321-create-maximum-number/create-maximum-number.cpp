// Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits.
//
// Note: You should try to optimize your time and space complexity.
//
// Example 1:
//
//
// Input:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
// k = 5
// Output:
// [9, 8, 6, 5, 3]
//
// Example 2:
//
//
// Input:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// Output:
// [6, 7, 6, 0, 4]
//
// Example 3:
//
//
// Input:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// Output:
// [9, 8, 9]
//


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        //核心思想是从两个数组中各组成一个最大的数，再对这两个数合并。
        vector<int> ans;
        int len1 = nums1.size(), len2 = nums2.size();
        
        //从nums1中取i个，从nums2中取k-i个。但要注意k和len1、len2间的关系
        // i 起始为max(0,k-len2),因为考虑到k可能比len2大，在nums1中至少要取k-len2个才可能凑到k个
        // i 结束为min(k,len1),考虑到可能需要取nums1中所有的数才凑得到k个
        for(int i = max(0,k-len2); i <= min(k,len1); ++i) {
            ans = max(ans, mergeNum(maxNum(nums1,i), maxNum(nums2,k-i)));
        }
        return ans;
    }
    
    vector<int> maxNum(vector<int> &nums, int k) {
        int drop = nums.size() - k;  //需要丢弃掉的数字个数
        vector<int> ans;
        for (int num : nums) {
            while(drop > 0 && !ans.empty() && ans.back() < num) {
                ans.pop_back();
                --drop;
            }
            ans.push_back(num);
        }
        ans.resize(k); //这里必须要resize，否则后续返回的数组长度不对，会导致结果多出几位
        return ans;
    }
    
    vector<int> mergeNum(vector<int> nums1, vector<int> nums2) {
        vector<int> ans;
        //每次取数组头部的最大值
        while (!nums1.empty() || !nums2.empty()) {
            vector<int> &nums = (nums1 > nums2) ? nums1 : nums2;
            ans.push_back(nums[0]);
            nums.erase(nums.begin());
        }
        return ans;
    }
};
