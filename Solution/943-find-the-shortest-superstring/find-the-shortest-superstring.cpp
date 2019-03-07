// Given an array A of strings, find any smallest string that contains each string in A as a substring.
//
// We may assume that no string in A is substring of another string in A.
//
//  
//
//
// Example 1:
//
//
// Input: ["alex","loves","leetcode"]
// Output: "alexlovesleetcode"
// Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//
//
//
// Example 2:
//
//
// Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
// Output: "gctaagttcatgcatc"
//
//  
//
//
//
// Note:
//
//
// 	1 <= A.length <= 12
// 	1 <= A[i].length <= 20
//
//
//
//  
//


class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int len = A.size();
        string res = "";
        //dp[mask][i],min superstring made by strings in mask,and the last one is A[i]. 
        //mask用0-1bit代表各个string的访问情况
        vector<vector<string>> dp(1<<len,vector<string>(len));
        //overlap[i][j]代表第i个字符串后面和第j个字符串前缀间的重合字符个数 eg: gcta & ctaagt = 3
        vector<vector<int>> overlap(len,vector<int>(len,0));
        
        //calculate overlap
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i!=j){
                    for(int k=min(A[i].size(),A[j].size());k>0;k--){
                        if(A[i].substr(A[i].size()-k) == A[j].substr(0,k)){
                            overlap[i][j] = k;
                            break;
                        }
                    }
                }
            }
        }
        
        //init
        for(int i=0;i<len;i++) dp[1<<i][i] += A[i];
        
        //dp
        for(int mask=1;mask<(1<<len);mask++){
            for(int j=0;j<len;j++){
                if((mask & (1<<j)) > 0){  //第j个字符串被访问
                    for(int i=0;i<len;i++){
                         if(i!=j && (mask&(1<<i))>0){  //第i个字符串被访问过
                             string tmp =  dp[mask^(1<<j)][i]+A[j].substr(overlap[i][j]);  //等于未访问过j的结果加上当前j字符串的结果
                             if(dp[mask][j].empty() || tmp.size()<dp[mask][j].size()){
                                 //cout<<tmp<<endl;
                                 dp[mask][j] = tmp;
                             }
                         }
                    }
                }
            }
        }
        
        //result
        int all_visit = (1<<len)-1;
        res = dp[all_visit][0];
        for(int i=1;i<len;i++){
            if(dp[all_visit][i].size() < res.size()) res = dp[all_visit][i];
        }
        
        return res;
    }
};
