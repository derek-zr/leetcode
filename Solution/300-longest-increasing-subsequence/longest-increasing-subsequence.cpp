// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
// Example:
//
//
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
//
// Note: 
//
//
// 	There may be more than one LIS combination, it is only necessary for you to return the length.
// 	Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity?
//


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
        
        //第二种是O(nlogn)的解法，用dp数组结合二分法求解长度
        //这里dp[i]表示的是i+1长度的LIS的最小结束字符
        //需要注意的一点是dp数组中的序列不表示最后真实的LIS序列，只是长度相等
        //为什么长度相等可以这么考虑：对于append的行为，肯定增加长度。对于replace的行为，因为找到了更小的结束字符，更有可能组成更长的串
        
        //FOLLOWUP:怎么复原整个LIS序列 
        
        int len = nums.size();
        vector<int> dp;       //存储的是在nums中的index
        vector<int> parent(len, -1);   //用来记录当前最长LIS的上一个点的index
        
        for (int i = 0; i < len; ++i) {
            int left = 0, right = dp.size();
            //查找插入位置，第一个不小于nums[i]的数字
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (nums[dp[mid]] < nums[i])  left = mid + 1;
                else right = mid;
            }
            //如果没有找到插入位置，则直接添加到后面
            if (right == dp.size())   dp.push_back(i);
            else  dp[right] = i;      //替换为更小的结束数字
            if(right - 1 >= 0) parent[i] = dp[right - 1];   //如果是头部节点的替换，则没有上一个index，无需记录
        }
        /*
        cout << "The LIS：" << endl;
        for (int i = dp.back(); i >= 0; i = parent[i]) {
            cout << nums[i] << "  ";
        }
        cout << endl;
        */
        
        return dp.size();
        
        /*
        //第一种是O(n2)的dp解法，表示以nums[i]结尾的最长LIS的长度
        int len = nums.size();
        vector<int> dp(len, 1);
        int ans = 0;     //在dp过程中记录最大值
        
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);    //...j, i形成一个LIS
                }
            } 
            ans = max(ans, dp[i]);
        }
        return ans;
        */
        
    }
};
