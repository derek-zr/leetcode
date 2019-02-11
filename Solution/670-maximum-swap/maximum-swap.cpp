//
// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
//
//
// Example 1:
//
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
//
//
//
// Example 2:
//
// Input: 9973
// Output: 9973
// Explanation: No swap.
//
//
//
//
// Note:
//
// The given number is in the range [0, 108]
//
//


class Solution {
public:
    //转为字符串后，从后向前遍历，找最大的数字和最高位的且小于最大数字的数
    int maximumSwap(int num) {
        string str_num = to_string(num);
        int left=-1,right=-1;
        int max_index=-1,max_num=-1;
        int len = str_num.size();
        for(int i=len-1;i>=0;--i){
            if(str_num[i]>max_num){
                max_num = str_num[i];
                max_index = i;
            }
            if(str_num[i]<max_num){
                left = i;
                right = max_index;
            }
        }
        
        if(left==-1) return num;
        swap(str_num[left],str_num[right]);
        return stoi(str_num);
    }
};
