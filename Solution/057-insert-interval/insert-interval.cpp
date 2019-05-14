// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int len = intervals.size();
        int i = 0;
        while(i < len) {
            if(intervals[i][1] < newInterval[0]) {
                //不重叠，即end小于新插入的start
                ans.push_back(intervals[i]);
                ++i;
            }
            else break;
        }
        //如果遇到重叠(可能有多个重叠)
        //新遍历的start小于合并区间的end则说明还有重叠，继续合并
        while(i < len && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            ++i;
        }
        //插入合并完成的区间
        ans.push_back(newInterval);
        //插入后续的区间
        while(i < len) {
            ans.push_back(intervals[i]);
            ++i;
        }
        
        return ans;
    }
};
