// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
//


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        //第一种方法，用unordered_set(不能用set，因为set是红黑树，建树复杂度为O(nlogn))
        //将所有元素先存进set中，遍历set。如果当前num-1 和 num+1 存在，则将其移除（避免重复搜索），在这个过程中计算最大长度
        if(nums.empty()) return 0;
        int ans = 0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int num : nums){
            if(!s.count(num)) continue;
            s.erase(num);       //删除num是为了减少重复计算，比如1 2 3 4, 如果不删除，则每次都会遍历一遍这几个数
            int small = num - 1 ,large = num + 1;
            while(s.count(small)) {s.erase(small);--small;}
            while(s.count(large)) {s.erase(large);++large;}
            ans = max(ans,large-small-1);
        }
        
        return ans;
        
        //第二种方法是用union find，将num的下标与num+1、num-1的下标合并起来。最后统计最大的size
    }
};
