// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
// Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.
//
// Note:
// A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
// Example:
//
//
// Input: nums = [-2,5,-1], lower = -2, upper = 2,
// Output: 3 
// Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
//


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //more concise
        //相当于这里用multiset作为前缀和数组，对于某一个前缀和sums[i]，找到符合条件的j的范围
        int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;
        
        /*
        //用mergeSort。在前缀和数组中不断寻找符合条件的组合。
        //mergeSort保证了左右有序后，对于左边的i，我们只要找到右边数组中lower+preSum[i] < preSum[j] < upper+preSum[i]的范围，加到最后的结果中。
        int len = nums.size();
        vector<long> preSum(len+1,0);
        //get preSum
        for (int i = 0; i < len; ++i) {
            preSum[i+1] = preSum[i] + nums[i];
        }
        return helper(preSum,0,len+1,lower,upper);
        */
    }
    
    int helper(vector<long> &preSum, int left, int right, int lower, int upper) {
        if (right-left <= 1) return 0;
        int mid = left + (right-left)/2;
        int ans = helper(preSum,left,mid,lower,upper) + helper(preSum,mid,right,lower,upper);  //先保证左右有序
        int j = mid, k = mid, t = mid;
        vector<int> tmp(right-left,0);  //排序
        for(int i = left, index = 0; i < mid; ++i,++index) {
            while(k < right && preSum[k]-preSum[i] < lower) ++k;
            while(j < right && preSum[j]-preSum[i] <= upper) ++j;
            //排序
            while(t < right && preSum[t] < preSum[i]) tmp[index++] = preSum[t++];
            ans += j - k;  //符合条件的范围长度
            //保证有序
            tmp[index] = preSum[i];
        }
        //保证preSum中left到t一段有序
        copy(tmp.begin(),tmp.begin()+t-left,preSum.begin()+left);
        return ans;
    }
};
