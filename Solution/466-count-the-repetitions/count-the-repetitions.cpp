// Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc". 
// On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc”  can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.
// You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.
//
// Example:
//
// Input:
// s1="acb", n1=4
// s2="ab", n2=2
//
// Return:
// 2
//
//


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        //https://www.cnblogs.com/grandyang/p/6149294.html
        //解法思路很巧妙。大致思路为先找s2在S1中出现了多少次，再除以n2即可得到S2对应的M
        //在这个过程中，通过找到对应的pattern（某个区间情况重复出现），可以快速计算得到次数
        vector<int> repeatCnt(n1+1,0);   //到某个位置时重复出现的次数
        vector<int> nextDesireIndex(n1+1,0);   //在下一个s1内，需要找到的匹配的s2[index]
        int j = 0 , cnt = 0;
        for (int r  = 1; r <= n1; ++r) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if(j == s2.size()) {  //匹配到了一串s2
                        j = 0;
                        ++cnt;  
                    }
                }
            }
            repeatCnt[r] = cnt;
            nextDesireIndex[r] = j;
            
            //从头开始找可能存在的pattern
            for (int start = 0; start < r; ++start) {
                if(nextDesireIndex[start] == j) {  //start与当前index的情况相同，pattern出现
                    int interval = r - start;
                    //计算整个存在多少个interval
                    int repeat = (n1 - start) / interval;
                    //每个interval中s2重复的次数*interval个数
                    int patternCnt = (repeatCnt[r] - repeatCnt[start]) * repeat;
                    //start前的和最后的一段，也可能出现重复次数，需要单独计算
                    int remainCnt = repeatCnt[start + (n1-start) % interval];
                    return (patternCnt + remainCnt) / n2;
                }
            }
        }
        return repeatCnt[n1] / n2;
    }
};
