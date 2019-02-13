// In a given 2D binary array A, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)
//
// Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
//
// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
//
//  
//
// Example 1:
//
//
// Input: [[0,1],[1,0]]
// Output: 1
//
//
//
// Example 2:
//
//
// Input: [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
//
//
//
// Example 3:
//
//
// Input: [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
//
//  
//
//
//
// Note:
//
//
// 	1 <= A.length = A[0].length <= 100
// 	A[i][j] == 0 or A[i][j] == 1
//
//
//
//
//  
//
//


class Solution {
public:
    //https://leetcode.com/problems/shortest-bridge/discuss/189293/C%2B%2B-BFS-Island-Expansion-%2B-UF-Bonus
    //先把其中一个岛标为2，再从2岛向外拓展，每拓展一步，修改0值为2+i。
    //当遇到为1的另一个岛时，则知桥的长度为当前2+i-2
    
    //paint辅助函数，修改其中一个岛的值为2
    int paint(vector<vector<int>>& A,int i ,int j){
        if(i<0||j<0||i==A.size()||j==A[0].size()||A[i][j]!=1) return 0;
        A[i][j]=2;
        return 1+paint(A,i+1,j)+paint(A,i-1,j)+paint(A,i,j+1)+paint(A,i,j-1);
    }
    
    int expand(vector<vector<int>>& A,int i ,int j,int step){
        if(i<0||j<0||i==A.size()||j==A[0].size()) return false;
        if(A[i][j]==0) A[i][j]=step+1;
        return A[i][j]==1;  //是否到达另一个岛
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        //paint
        bool is_island = false; //paint only one of the islands
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(is_island) break;
                is_island=paint(A,i,j);
            }
            if(is_island) break;
        }
        //expand
        int step=2;
        for(step;;++step){
            for(int i=0;i<A.size();i++){
                for(int j=0;j<A[0].size();j++){
                    if((A[i][j]==step)&&(expand(A,i+1,j,step)||expand(A,i-1,j,step)||expand(A,i,j+1,step)||expand(A,i,j-1,step))){
                        return step-2;
                    }
                }
            }
        }
    }
};
