// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Given two integers x and y, calculate the Hamming distance.
//
// Note:
// 0 ≤ x, y < 231.
//
//
// Example:
//
// Input: x = 1, y = 4
//
// Output: 2
//
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
//
// The above arrows point to positions where the corresponding bits are different.
//
//


class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance=0;
        int n=x^y; //n中1的个数即distance
        while(n)
        {   
            distance++;
            n=n&(n-1);
        }
        return distance;
    }
};
