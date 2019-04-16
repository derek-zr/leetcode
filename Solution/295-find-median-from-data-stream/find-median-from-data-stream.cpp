// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// For example,
//
// [2,3,4], the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Design a data structure that supports the following two operations:
//
//
// 	void addNum(int num) - Add a integer number from the data stream to the data structure.
// 	double findMedian() - Return the median of all elements so far.
//
//
//  
//
// Example:
//
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
//
//
//  
//
// Follow up:
//
//
// 	If all integer numbers from the stream are between 0 and 100, how would you optimize it?
// 	If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
//
//


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);  
        large.push(-small.top());  //在大堆中先取反再放入，因为堆默认从大到小排列
        small.pop();
        
        if(small.size() < large.size()) {  //始终保存小堆的数目更多，即堆顶为中位数
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) return small.top();
        return 0.5 * (small.top()-large.top());
    }

private:
    priority_queue<int> large,small;
    //一个堆中保存大于中位数的值，一个堆中保存小于等于中位数的值
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
