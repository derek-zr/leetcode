// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.
//
//


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //这道题可以用mergesort的思想，也可以用二叉索引树。这里用mergesort的方法，因为更巧妙，也更符合题目的要求。
        //mergesort用的是分治的方法，将数组不停的分为前后两段，递归求解前后段中的reverse pairs。
        //同时，对于前半段的每个数字，我们计算后半段中的reverse pairs数目，将两者相加即可得到最终结果。
        //至于为什么要用mergesort，因为以上都基于一个假设，数组是有序的，用mergesort可以自然的将复杂度降为n * log(n)
        return mergeSortAndCount(nums, 0, nums.size()-1);
    }
    
    
    int mergeSortAndCount(vector<int>& nums, int start, int end) {
        if (start >= end)  return 0;
        int mid = start + (end - start) / 2;
        int ans = mergeSortAndCount(nums, start, mid) + mergeSortAndCount(nums, mid+1, end);
        //遍历前半段的每个数字，找到其对应的reverse pairs数目
        for (int i = start, j = mid+1; i < mid+1; ++i) {
            while (j <= end && nums[j]*2.0 < nums[i])  ++j;
            ans += j - (mid+1); 
        }
        //现在对前半段(有序)和后半段(有序)合并成一个更长的有序数组
        vector<int> left(mid-start+1), right(end-mid);
        for (int i = start; i <= mid; ++i) left[i-start] = nums[i];
        for (int i = mid+1; i <= end; ++i) right[i-mid-1] = nums[i];
        //merge STL函数： merge (first,first+5,second,second+5,v.begin());
        merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin()+start);
        //for (int i = start; i <= end; ++i) cout << nums[i];
        //cout<<endl;
        return ans;
    }
};
