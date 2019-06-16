// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
//


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //用桶排序做。先找到数组中的最大值和最小值确定gap，根据gap决定桶的数目。再将数组中的数字分别放到对应的桶中，接着扫描相邻的桶即可。The maximum gap is only dependent on the maximum number of the current bucket and the minimum number of the next neighboring bucket (the bucket should not be empty). 
        //这里我们用到一个技巧，只保存一个桶中的最大值和最小值。
        int len = nums.size();
        if(len < 2) return 0;
        int mi = INT_MAX, mx = INT_MIN;
        for(int num : nums) {
            mi = min(mi,num);
            mx = max(mx,num);
        }
        //根据最大值和最小值计算gap
        int gap = max((mx-mi)/(len-1),1);  //防止gap为0的情况
        int cnts = (mx-mi)/gap + 1;  //计算桶的数目
        
        //保存某一个桶中的最大值和最小值
        vector<int> bucketMin(cnts,INT_MAX);
        vector<int> bucketMax(cnts,INT_MIN);
    
        //将数组的数字放入对应的桶中
        for(int num : nums) {
            int k = (num-mi) / gap;
            //更新扫描到的最大值和最小值
            if(num < bucketMin[k]) bucketMin[k] = num;
            if(num > bucketMax[k]) bucketMax[k] = num;
        }
        
        //扫描相邻桶找到最大gap
        int i = 0, j;
        gap = bucketMax[0] - bucketMin[0];
        while(i < cnts) {
            j = i + 1;
            while(j < cnts && bucketMin[j]==INT_MAX && bucketMax[j]==INT_MIN){
                ++j;  //跳过空的桶
            }
            if(j == cnts) break;
            gap = max(gap,bucketMin[j]-bucketMax[i]);  //相邻桶间求差值
            i = j;
        }
        return gap;
    }
};
