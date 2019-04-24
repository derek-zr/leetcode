// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
//
//
//
// Example 2:
//
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
//
//
// Note:
//
//
// 	Each element in the result should appear as many times as it shows in both arrays.
// 	The result can be in any order.
//
//
// Follow up:
//
//
// 	What if the given array is already sorted? How would you optimize your algorithm?
// 	What if nums1's size is small compared to nums2's size? Which algorithm is better?
// 	What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
//
//


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //follow up 
        //如果两个数组都是sort的，可以通过双指针来减少map的空间使用。分别遍历两个数组，相等则加入，不相等则向后移动
        unordered_map<int,int> m;
        vector<int> ans;
        if(nums1.size() > nums2.size()) {
            for(int num : nums2) ++m[num];
            for(int num : nums1) {
                if(m[num]-- > 0) ans.push_back(num);
            }
        }
        else {
            for(int num : nums1) ++m[num];
            for(int num : nums2) {
                if(m[num]-- > 0) ans.push_back(num);
            }
        }
        
        return ans;
    }
};
