// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)
//
//
//
// Examples: 
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.
//
//


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        long left=0,right=0;
        long mid=0;
        for(int i=0;i<n;i++){
            left=max(left,(long)nums[i]);  //左极限是数组中的最大值
            right+=nums[i];          //右极限是数组的和
        }
        
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(canSplit(nums,m-1,mid)) right=mid;
            else left=mid+1;
        }
        return right;
    }
    
    bool canSplit(vector<int>& nums, int cuts,long max)
    {
        long acc=0;
        for(int num:nums)
        {
            if(num>max) return false;
            else if(acc+num<=max) acc+=num;
            else
            {
                cuts--;
                acc=num;
                if(cuts<0) return false;
            }
        }
        return true;
    }
};
