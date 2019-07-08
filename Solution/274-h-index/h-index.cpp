// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//
// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."
//
// Example:
//
//
// Input: citations = [3,0,6,1,5]
// Output: 3 
// Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
//              received 3, 0, 6, 1, 5 citations respectively. 
//              Since the researcher has 3 papers with at least 3 citations each and the remaining 
//              two with no more than 3 citations each, her h-index is 3.
//
// Note: If there are several possible values for h, the maximum one is taken as the h-index.
//


class Solution {
public:
    int hIndex(vector<int>& citations) {
        //桶排序的思想。总共有n篇论文，则我们建立n+1个桶，统计每个桶内的次数。
        int len = citations.size();
        vector<int> buckets(len+1,0);
        for(int c : citations) {
            if(c >= len) ++buckets[len];
            else ++buckets[c];
        }
        int cur_paper = 0;
        for(int i = len; i >= 0; --i) {
            cur_paper += buckets[i];
            if(cur_paper >= i) return i;
        }
        return len;
        /*
        //简单的方法就是sort，然后找下标大于对应位置值的
        sort(citations.begin(),citations.end(),greater<int>());
        int len = citations.size();
        for(int i = 0; i < len; ++i) {
            if(i >= citations[i]) return i;
        }
        return len;
        */
    }
};
