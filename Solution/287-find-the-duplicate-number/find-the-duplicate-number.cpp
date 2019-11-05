// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
//
// Example 1:
//
//
// Input: [1,3,4,2,2]
// Output: 2
//
//
// Example 2:
//
//
// Input: [3,1,3,4,2]
// Output: 3
//
// Note:
//
//
// 	You must not modify the array (assume the array is read only).
// 	You must use only constant, O(1) extra space.
// 	Your runtime complexity should be less than O(n2).
// 	There is only one duplicate number in the array, but it could be repeated more than once.
//
//


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //O(n)解法。这道题和找链表环的入口点一样，
        
        //第一步用快慢指针找到环
        int slow = 0, fast = 0, start = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)  break;
        }
        
        //找环的入口点，一个从头走，一个从相遇点走
        while (true) {
            slow = nums[slow];
            start = nums[start];
            if (slow == start)  break;
        }
        
        return slow;
        
        /*
        //第一种用二分法，先找到1-n的mid，再统计数组中大于mid和小于mid的数目。O(nlogn)
        int left = 0, right = nums.size();
        while(left < right) {
            int mid = left + (right-left)/2;
            int cnts = 0;
            for(int num : nums) {
                if(num <= mid) ++cnts;   //统计小于mid的数量
            }
            
            if(cnts > mid) right = mid; //重复值出现在左半段
            else if(cnts <= mid) left = mid+1;  //重复值出现在右半段
        }
        
        return right;
        */
    }
};
