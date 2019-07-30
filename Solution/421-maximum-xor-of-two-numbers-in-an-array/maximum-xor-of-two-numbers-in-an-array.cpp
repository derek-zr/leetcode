// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.
//
//
//  
//


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //核心思想：找最终结果中谁贡献了每个位置上的1
        //二进制逐位取出，找出每个位置上可能得到的值
        int ans = 0, mask = 0;
        for(int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for(int num : nums) {
                s.insert(num & mask);
            }
            int tmp = ans | (1<<i);
            //验证能否得到该结果，利用a^b=c -> a=b^c
            for(int prefix : s) {
                if(s.count(tmp ^ prefix)) {
                    ans = tmp;
                    break;
                }
            }
        }
        return ans;
    }
};
