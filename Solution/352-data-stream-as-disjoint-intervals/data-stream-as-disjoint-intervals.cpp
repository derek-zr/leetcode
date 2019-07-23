// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
//
//
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
//
//
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


class SummaryRanges {
public:
    SummaryRanges() {}
    
    void addNum(int val) {
        vector<int> newInterval{val, val};
        //找相交的intervals,overlap表示相交的数目
        int i = 0, overlap = 0, n = intervals.size();
        for (; i < n; ++i) {
            if (newInterval[1] + 1 < intervals[i][0]) break;  //不相交 
            if (newInterval[0] <= intervals[i][1] + 1) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
                ++overlap;
            }
        }
        
        //去除相交的部分
        if (overlap > 0) {
            intervals.erase(intervals.begin() + i - overlap, intervals.begin() + i);
        }
        //插入新合并的部分
        intervals.insert(intervals.begin() + i - overlap, newInterval);
    }
    vector<vector<int>> getIntervals() {
        return intervals;
    }
private:
    vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
