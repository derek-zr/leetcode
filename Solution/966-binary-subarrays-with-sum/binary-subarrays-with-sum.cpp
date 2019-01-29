// In an array A of 0s and 1s, how many non-empty subarrays have sum S?
//
//  
//
// Example 1:
//
//
// Input: A = [1,0,1,0,1], S = 2
// Output: 4
// Explanation: 
// The 4 subarrays are bolded below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
//
//
//  
//
// Note:
//
//
// 	A.length <= 30000
// 	0 <= S <= A.length
// 	A[i] is either 0 or 1.
//


class Solution {
public:
    //字串相加，考虑前缀和。
    //sum(i,j)=pre(j)-pre(i)
    //考虑到只有01，这里不需要用map。因为presum只可能为1-n
    int numSubarraysWithSum(vector<int>& A, int S) {
        int n = A.size();
        vector<int> pre(n+1,0);
        int sum = 0;
        int cnts = 0;
        for(auto i : A){
            sum += i;
            if(sum-S >= 0) cnts += pre[sum-S];
            if(sum==S) cnts++;
            pre[sum]++;
        }
        
        return cnts;
    }
};
