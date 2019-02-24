// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    //在两个数组间进行二分查找
    //https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 < len2) return findMedianSortedArrays(nums2,nums1);  //在较短的数组内做分割，更容易找到结果
        
        int left = 0,right = 2* len2;
        while(left<=right){
            int mid2 = left + (right-left)/2;
            int mid1 = len1+len2-mid2;
            
            double L1 = (mid1==0)? INT_MIN : nums1[(mid1-1)/2];
            double L2 = (mid2==0)? INT_MIN : nums2[(mid2-1)/2];
            double R1 = (mid1==2*len1)? INT_MAX : nums1[(mid1)/2];
            double R2 = (mid2==2*len2)? INT_MAX : nums2[(mid2)/2];
            
            if(L1 > R2) left = mid2 + 1;
            else if(L2 > R1) right = mid2 -1;
            else return (max(L1,L2)+min(R1,R2)) /2;
        }
        
        return -1;
    }
};
