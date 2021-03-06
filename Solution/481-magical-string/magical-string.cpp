//
// A magical string S consists of only '1' and '2' and obeys the following rules:
//
//
// The string S is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string S itself.
//
//
//
// The first few elements of string S is the following:
// S = "1221121221221121122……"
//
//
//
// If we group the consecutive '1's and '2's in S, it will be:
//
//
// 1   22  11  2  1  22  1  22  11  2  11  22 ......
//
//
// and the occurrences of '1's or '2's in each group are:
//
//
// 1   2	   2    1   1    2     1    2     2    1    2    2 ......
//
//
//
// You can see that the occurrence sequence above is the S itself. 
//
//
//
// Given an integer N as input, return the number of '1's in the first N number in the magical string S.
//
//
// Note:
// N will not exceed 100,000.
//
//
//
// Example 1:
//
// Input: 6
// Output: 3
// Explanation: The first 6 elements of magical string S is "12211" and it contains three 1's, so return 3.
//
//


class Solution {
public:
    int magicalString(int n) {
        //从第三个开始迭代生成
        //根据第三个数字2开始往后生成数字，此时生成两个1，然后根据第四个数字1，生成一个2，再根据第五个数字1，生成一个1，
        //以此类推，生成的数字1或2可能通过异或3来交替生成，在生成的过程中同时统计1的个数即可
        if(n <= 0) return 0;
        if(n <= 3) return 1;
        int ans = 1;
        int length_index = 2 , tail = 3, num = 1;
        vector<int> v{1, 2, 2};
        //迭代
        while(tail < n) {
            //根据当前的length_index指向的值生成1或2
            for(int i = 0; i < v[length_index]; ++i) {
                v.push_back(num);
                if(num == 1 && tail < n) ++ans;
                ++tail;
            }
            //交替生成1和2
            num ^= 3;
            ++length_index;
        }
        return ans;
    }
};
