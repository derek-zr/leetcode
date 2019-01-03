//
// You are standing at position 0 on an infinite number line.  There is a goal at position target.
//
// On each move, you can either go left or right.  During the n-th move (starting from 1), you take n steps.
//
// Return the minimum number of steps required to reach the destination.
//
//
// Example 1:
//
// Input: target = 3
// Output: 2
// Explanation:
// On the first move we step from 0 to 1.
// On the second step we step from 1 to 3.
//
//
//
// Example 2:
//
// Input: target = 2
// Output: 3
// Explanation:
// On the first move we step from 0 to 1.
// On the second move we step  from 1 to -1.
// On the third move we step from -1 to 2.
//
//
//
// Note:
// target will be a non-zero integer in the range [-10^9, 10^9].
//


class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long n = ceil((-1.0+sqrt(1.0+8.0*target))/2.0);  //1到n累加值大于target的最小n。即求解求和公式n*(n+1)/2=target
        //上式一定要加.0，否则计算会有问题
        long sum = n*(n+1)/2;
        if(sum==target) return n;
        if((sum-target)%2==0) return n;  //差值为偶数时，只需要将n步中的某一步改为-x即可。（相当于差了2x）
        return (n%2==0) ? n+1 : n+2;     //如果是奇数，判断此时n的奇偶，如果n是奇数，则返回n+2（需要加上n+1，n+2使差值为偶数），若n是偶数，返回n+1（加上n+1使差值为偶数）   
    }
};
