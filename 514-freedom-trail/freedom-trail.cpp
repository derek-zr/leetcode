// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.
//
// Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
//
// Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button.
//
// At the stage of rotating the ring to spell the key character key[i]:
//
//
// 	You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
// 	If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
//
//
// Example:
//
//
//  
//
//
// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
// For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
// For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
// Also, we need 1 more step for spelling.
// So the final output is 4.
//
//
// Note:
//
//
// 	Length of both ring and key will be in range 1 to 100.
// 	There are only lowercase letters in both strings and might be some duplcate characters in both strings.
// 	It's guaranteed that string key could always be spelled by rotating the string ring.
//
//


/*
动态规划记录当前的状态result[i][j]，即当前匹配到key的第i个字母，ring的第j个字母在12点方向，要匹配key的下一个字母时，可以从上一个状态顺时针或者逆时针转移到现在的状态.结尾的+key.length()是因为选中后需要按button，每次按button算一次步骤.
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int rsize=ring.size();
        int ksize=key.size();
        vector<int> index[26];  //26个数组,不是一个含26元素的数组
        for(int i=0;i<rsize;i++)
            index[ring[i]-'a'].push_back(i);
        
        vector<vector<int>> dp(ksize+1,vector<int>(rsize,INT_MAX));
        dp[ksize].assign(rsize,0);
        for(int i=ksize-1;i>=0;i--) 
            for(int j=0;j<rsize;j++)
                for(int nxt:index[key[i]-'a']) {
                    int dist = abs(j-nxt);
                    dp[i][j]=min(dp[i][j],min(dist,rsize-dist)+dp[i+1][nxt]);
                }
        return dp[0][0]+ksize;
    }
};
