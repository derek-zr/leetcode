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


class Solution {
public:
    int findRotateSteps(string ring, string key) {
        //这道题可以用带memo的dfs或者dp求解
        
        //对于dfs， 我们记memo[i][j]为从ring字符十二点方向为ring[i]的情况与从j开始的key字符间的匹配关系
        int len1 = ring.size(), len2 = key.size();
        vector<vector<int> > charas(26);   //某个字符出现的下标数组
        for (int i = 0; i < len1; ++i)  charas[ring[i] - 'a'].push_back(i);
        vector<vector<int> > memo(len1, vector<int>(len2));
        
        return helper(ring, key, 0, 0, charas, memo);     //memo[0][0], 最终的结果
        
    }
    
    int helper(string &ring, string &key, int i, int j, vector<vector<int> > &charas, vector<vector<int> > &memo) {
        if (j == key.size())  return 0;    //已经遍历完了key
        if (memo[i][j])   return memo[i][j];
        int minSteps = INT_MAX, len = ring.size();
        //开始遍历，ring中可能含有多个和key[j]相等的字符
        for (int k : charas[key[j] - 'a']) {
            int diff = abs(i - k);
            //考虑顺时针或逆时针转，两者步数相加等于总长度
            int curSteps = min(diff, len - diff);
            minSteps = min(minSteps, curSteps + helper(ring, key, k, j + 1, charas, memo));
        }
        
        memo[i][j] = minSteps + 1;     //one more step for spelling
        return memo[i][j];
    }
};
