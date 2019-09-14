// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //不断比较压入数组的最后一个end和新遍历到的start大小关系
        //如果小于则可以直接压入，如果大于则需要更新上一个end
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        int len = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        //遍历
        for(int i = 1; i < len; ++i) {
            if(ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
