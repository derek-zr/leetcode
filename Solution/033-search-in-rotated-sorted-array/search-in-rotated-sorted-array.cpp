// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //二分法
        if (nums.empty())  return -1;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            //这里采用另一种方法，通过比较target和nums[mid]是不是处在同一个半段
            //如果处在同一个半段，那说明退化成了正常的二分查找，能够收敛
            //如果处在不同的半段，为了在target所在的分段查找，我们需要把nums[mid]置为正无穷或负无穷，来跳过其所在的分段
            int cmp = nums[mid];
            if ( (target < nums[0]) == (nums[mid] < nums[0]) )
                cmp = nums[mid];
            else {
                //target在左半段
                if (target >= nums[0])
                    cmp = INT_MAX;
                else 
                    cmp = -INT_MAX;
            }
            //cout << left << right << mid << endl;
            //此时再进行二分比较
            //在右半段找
            if (target > cmp)
                left = mid + 1;
            else if (target < cmp)
                right = mid;
            else 
                return mid;
        }
        //cout << right;
        //if (right != nums.size() && nums[right] == target)  return right;
        return -1;
        
        /*
        //二分法。难点在于二分条件的寻找
        if (nums.empty()) return -1;
        int left = 0, right = nums.size()-1;    //这里必须要初始化为size-1,因为我们需要和nums[right]比较大小，那么必须要求right对应的下标是有效的
        //二分
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            //这里和right比较的原因是：mid有可能和left相等，例如对于一个长度为2的数组
            else if (nums[mid] > nums[right]) {   //左半段是有序
                //判断是否在左半段中
                if (nums[left] <= target && nums[mid] > target) right = mid-1;  
                else left = mid + 1;
            }
            else {   //右半段有序
                 //判断是否在右半段
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            }
        }
        */
        return -1;
    }
};
