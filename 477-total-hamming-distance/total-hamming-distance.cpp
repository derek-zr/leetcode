// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Now your job is to find the total Hamming distance between all pairs of the given numbers.
//
//
// Example:
//
// Input: 4, 14, 2
//
// Output: 6
//
// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
// showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
//
//
//
// Note:
//
// Elements of the given array are in the range of 0  to 10^9
// Length of the array will not exceed 10^4. 
//
//


class Solution {
public:
    //二进制表示时，每一列(二进制位)上零的个数乘以一的个数
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int len = nums.size();
        for(int i=0;i<32;i++){  //不超过10^9
            int cnt1s = 0;
            for(int num : nums){
                if(num & (1<<i)) cnt1s++;  //该位置上是1
            }
            ans += cnt1s * (len-cnt1s);
        }
        
        return ans;
    }
};
