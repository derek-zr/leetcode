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
    //在两个数组中找Kth的数，则我们考虑对K进行二分，不断在两个数组中找K/2th的数
    //如果某个数组不存在K/2个元素，则可以直接丢弃另一个数组的前K/2个元素（因为即使加上当前全部的数组，也达不到K）
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size() , len2 = nums2.size();
        //根据总长度的奇偶情况，中位数是中间那个数或者中间两个数的平均值
        int num1 = (len1 + len2 + 1) / 2 , num2 = (len1 + len2 + 2) / 2;    //奇数时num1和num2相等
        return (helper(nums1 , 0 , nums2 , 0 , num1) + helper(nums1, 0 , nums2 , 0 , num2)) / 2.0;
    }
    
    double helper(vector<int>& nums1, int start1 , vector<int>& nums2, int start2, int k) {
        //先判断某个数组是否已经别完全舍弃
        if(start1 >= nums1.size()) return nums2[start2+k-1];   //直接在另一个数组中找
        if(start2 >= nums2.size()) return nums1[start1+k-1];
        if(k == 1) return min(nums1[start1], nums2[start2]);   //找第一个直接返回两者中的较小值
        //找两者K/2位置的，如果不存在则赋值为MAX
        int mid1 = (start1 + k/2 - 1 < nums1.size()) ? nums1[start1 + k/2 - 1] : INT_MAX;
        int mid2 = (start2 + k/2 - 1 < nums2.size()) ? nums2[start2 + k/2 - 1] : INT_MAX;
        //对K二分
        if(mid1 < mid2) {
            //舍弃mid1的前K/2
            return helper(nums1, start1+k/2 , nums2, start2, k - k/2);  //这里必须是k-k/2,才能正确处理k为奇数的情况
        }
        else {
            return helper(nums1, start1 , nums2, start2+k/2, k - k/2);
        }
    }
    
    /*
    //在两个数组间进行二分查找
    //https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/very-concise-ologminmn-iterative-solution-with-detailed-explanation
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 > len2) return findMedianSortedArrays(nums2,nums1);  //在较短的数组内做分割，更容易找到结果
        
        int left = 0,right = len1;
        while(left<=right){
            int mid1 = left + (right-left)/2;
            int mid2 = (len1+len2+1)/2 -mid1;
            
            double L1 = (mid1==0)? INT_MIN : nums1[mid1-1];
            double L2 = (mid2==0)? INT_MIN : nums2[mid2-1];
            double R1 = (mid1==len1)? INT_MAX : nums1[mid1];
            double R2 = (mid2==len2)? INT_MAX : nums2[mid2];
            
            if(L1 > R2) right = mid1 -1;
            else if(L2 > R1) left = mid1 + 1;
            else{
                if((len1+len2)%2==0) return (max(L1,L2)+min(R1,R2)) /2;
                else return max(L1,L2);
            }
        }
        
        return -1;
    }
    */
};
