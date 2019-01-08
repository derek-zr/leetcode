//
// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:
//
// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
//
//
//
//
// Now given N, how many beautiful arrangements can you construct?
//
//
// Example 1:
//
// Input: 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1, 2]:
// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
// The second beautiful arrangement is [2, 1]:
// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
//
//
//
// Note:
//
// N is a positive integer and will not exceed 15.
//
//


class Solution {
public:
    //dfs
    int countArrangement(int N) {
        int ans=0;
        int tmplen=1;
        vector<bool> visited(N,0);
        dfs(ans,tmplen,N,visited);
        return ans;
    }
    
    void dfs(int& ans,int tmplen, int N,vector<bool>& visited){
        for(int i=1;i<=N;i++){
            if(visited[i-1]==0 && (i%tmplen==0||tmplen%i==0)){
                if(tmplen==N){
                    ans++;
                    return;
                }
                visited[i-1]=1;
                dfs(ans,tmplen+1,N,visited);
                visited[i-1]=0;
            }
        }
    }
};
