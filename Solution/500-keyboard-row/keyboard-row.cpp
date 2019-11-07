// Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
//
//  
//
//
//  
//
// Example:
//
//
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
//
//
//  
//
// Note:
//
//
// 	You may use one character in the keyboard more than once.
// 	You may assume the input string will only contain letters of alphabet.
//
//


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> alpha(3);
        alpha[0] = "qwertyuiop";
        alpha[1] = "asdfghjkl";
       alpha[2] = "zxcvbnm";
        vector<string> ans;
        for(int i = 0; i < words.size(); i++){
            int tmp = (alpha[0].find(tolower(words[i][0]))!=string::npos)? 0 : ((alpha[1].find(tolower(words[i][0]))!=string::npos) ? 1 : 2);
            bool flag = true;
            for(int j = 1; j < words[i].size(); j++){
                if(alpha[tmp].find(tolower(words[i][j])) == string::npos) { flag=false; break;}
            }
            if(flag) ans.push_back(words[i]);
        }
        return ans;
    }
};
