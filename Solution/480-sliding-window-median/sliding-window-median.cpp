// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// Examples: 
// [2,3,4] , the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5 
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
//
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//
// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
//
//
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
//
// Note: 
// You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //找中位数，维护两个set，分别存放有序数组中左半段和右半段的数字，并且保持small的长度大于等于large长度
        vector<double> ans;
        multiset<int> small , large; //用multiset，允许出现相同值
        int len = nums.size();
        for(int i = 0; i < len; ++i) {
            if(i >= k) {  //窗口大小达到，需要删除最左端的值
                if(small.count(nums[i-k])) small.erase(small.find(nums[i-k]));  //find只会返回第一个找到了，即只删除一个
                else if(large.count(nums[i-k])) large.erase(large.find(nums[i-k]));
            }
            //平衡small和large的大小
            if(small.size() <= large.size()) {
                //保证small的size大于等于large
                if(large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
                else {  //需要根据大小重新平衡
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            }
            else {
                if(nums[i] >= *small.rbegin()) large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());   //end指向最后一个元素的下一个元素
                    //small.erase(small.rbegin()); 不能删除reverse_iterator
                    small.insert(nums[i]);
                }
            }
            //平衡好后计算中位数
            if(i >= (k-1)) {
                //奇偶
                if(k % 2) ans.push_back(*small.rbegin());
                else ans.push_back((double)((double)*small.rbegin()+*large.begin()) / 2);
            }
        }
        return ans;
    }
};
