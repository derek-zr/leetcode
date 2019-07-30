// A password is considered strong if below conditions are all met:
//
//
//  It has at least 6 characters and at most 20 characters. 
//  It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit. 
//  It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met). 
//
//
// Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.
//
// Insertion, deletion or replace of any one character are all considered as one change.


class Solution {
public:
    int strongPasswordChecker(string s) {
        //细节题，不会....面试考到也是跪Q_Q
         int n = s.size();
        if (!n) {
            return 6;            
        }
        
        int repeat = 1;
        int replace = 0;
        int remove = 0;
        int add = 0;
        char cur = s[0];
        int lower = isLower(cur);
        int upper = isUpper(cur);
        int number = isNumber(cur);

        vector<int> repeatVec;
        
        for (int i = 1; i < n; ++i) {
            lower += isLower(s[i]);
            upper += isUpper(s[i]);
            number += isNumber(s[i]);
            if (s[i] == cur) {
                ++repeat;
            }
            if (s[i] != cur || i == n-1){
                replace += repeat/3;
                add += (repeat-1)/2;
                remove += max(0, repeat - 2);
                if (repeat > 2) {
                    repeatVec.push_back(repeat);
                }
                repeat = 1;
                cur = s[i];
            }
        }
        
        int miss = 0;
        if (!lower)
            ++miss;
        if (!upper)
            ++miss;
        if (!number)
            ++miss;
        
        if (n < 6) {
            return max(max(6 - n, miss), add);
        }
        
        if (n <= 20) {
            return max(replace, miss);
        }
        
        int needRemove = n - 20;
        if (needRemove >= remove) {
            return needRemove + miss;
        } else {
            int R = needRemove;
            int m = repeatVec.size();
            vector<vector<int>> dp(R+1, vector<int>(m+1, INT_MAX));
            dp[0][0] = 0;
            for (int j = 1; j <= m; ++j) {
                dp[0][j] = dp[0][j-1] + repeatVec[j-1]/3;
            }
            
            for (int r = 1; r <= R; ++r) {
                for (int j = 1; j <= m; ++j) {
                    for (int s = 0; s <= min(repeatVec[j-1]-2, r); ++s) {
                        if (dp[r-s][j-1] < INT_MAX) {
                            dp[r][j] = min(dp[r][j], dp[r-s][j-1] + (repeatVec[j-1]-s)/3);
                        }
                    }
                }
            }
            
            return needRemove + max(dp[R][m], miss);
        }
    }
    
    bool isLower(char c) {
        return c >= 'a' && c <= 'z';
    }
    
    bool isUpper(char c) {
        return c >= 'A' && c <= 'Z';
    }
    
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
};
