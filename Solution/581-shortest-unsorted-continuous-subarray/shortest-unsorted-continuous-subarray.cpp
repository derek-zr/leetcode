// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=. 
//
//


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        //第三种方法优化上面的第二种方法，空间复杂度为O(1)
        int len = nums.size();
        int mx = nums[0], mn = nums[len-1];
        int start = 0, end = -1;  //当初始数组有序时，end-start+1=0
        for(int i = 1; i < len; ++i) {
            mx = max(mx,nums[i]);
            mn = min(mn,nums[len-1-i]);
            if(mx > nums[i]) end = i;  //说明存在逆序
            if(mn < nums[len-1-i]) start = len-1-i;
        }
        return end-start+1;
        /*
        //第二种方法，直接排序。比较各个位置的值
        int len = nums.size();
        int i = 0, j = len-1;
        vector<int> tmp = nums;
        sort(tmp.begin(),tmp.end());
        while(i < len && tmp[i]==nums[i]) ++i;
        while(j > i && tmp[j]==nums[j]) --j;
        return j-i+1;
        */
        /*
        //第一种方法：找到一个逆序对。则向前找到其应该在的位置
        //例如1,3,5,4,2 找到第一个逆序4时，其位置应该在2处
        int len = nums.size();
        int ans = 0,start = -1;
        for(int i = 1; i < len; ++i) {
            if(nums[i] < nums[i-1]) {
                int j = i;
                while(j > 0 && nums[j] < nums[j-1]) {
                    swap(nums[j],nums[j-1]);
                    --j;
                }
                if(start ==-1 || j < start) start = j;  //start更新为更小的值
                ans = i-start+1;
            }
        }
        return ans;*/
    }
};
