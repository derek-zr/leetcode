// Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.
//
// What is the most number of chunks we could have made?
//
// Example 1:
//
//
// Input: arr = [4,3,2,1,0]
// Output: 1
// Explanation:
// Splitting into two or more chunks will not return the required result.
// For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
//
//
// Example 2:
//
//
// Input: arr = [1,0,2,3,4]
// Output: 4
// Explanation:
// We can split into two chunks, such as [1, 0], [2, 3, 4].
// However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
//
//
// Note:
//
//
// 	arr will have length in range [1, 10].
// 	arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
//
//
//  
//


class Solution {
public:
    //use max to keep track of the max value until the current position, and compare it to the sorted array (indexes from 0 to arr.length - 1). If the max equals the element at index i in the sorted array, then the final count++.
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0) return 0;
        int maxValue = 0;
        int cnts = 0;
        int len = arr.size();
        for(int i=0;i<len;i++){
            maxValue = max(maxValue,arr[i]);
            if(maxValue==i) cnts++;
        }
        
        return cnts;
    }
};
