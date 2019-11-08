// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //前缀和数组找边界
        int len = nums.size(), ans = INT_MAX;
        vector<int> preSum(len + 1, 0);
        for (int i = 1; i <= len; ++i) preSum[i] = preSum[i-1] + nums[i-1];
        //二分法找边界
        for (int i = 0; i < len; ++i) {
            //注意！！！preSum数组比nums数组要长一个，所以二分边界要注意
            int left = i + 1, right = len + 1, target = preSum[i] + s;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if (preSum[mid] < target) left = mid + 1;
                else right = mid;
            }
            //cout<<left<<right<<i<<endl;
            if (right == len+1) break;
            ans = min(ans, right - i);
        }
        
        return ans == INT_MAX ? 0 : ans;
        
        
        /*
        //双指针
        int len = nums.size(), left = 0, sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
            while (left <= i && sum >= s) {
                ans = min(ans, i - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
        */
        
        /*
        //O(nlogn) 在前缀和数组里面找右边界
        int len = nums.size(), ans = INT_MAX;
        vector<int> sums(len+1,0);
        for(int i = 1; i <= len; ++i) sums[i] = sums[i-1]+nums[i-1];
        
        for(int i = 0; i < len; ++i) {
            int left = i+1, right = len, target = sums[i]+s;
            //找到右边界
            while(left <= right) {
                int mid = left + (right-left)/2;
                if(sums[mid] < target) left = mid+1;
                else right = mid-1;
            }
            if(left == len+1) break;
            ans = min(ans,left-i);
        }
        return ans==INT_MAX? 0 : ans;
        */
        
        /* O(n)
        //双指针，在遍历中不断移动左指针
        int len = nums.size(), left = 0, sum = 0;
        int ans = INT_MAX;
        
        //开始遍历
        for(int i = 0; i < len; ++i) {
            sum += nums[i];
            while(left <= i && sum >= s) {
                ans = min(ans,i-left+1);
                sum -= nums[left++];  //移动左指针
            }
        }
        return ans==INT_MAX ? 0 : ans; 
        */
    }
};
