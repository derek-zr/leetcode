//
// Given an encoded string, return it's decoded string.
//
//
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//
//
// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
//
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
//
//
// Examples:
//
// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
//
//


class Solution {
public:
    string decodeString(string s) {
        int len=s.size();
        string ans="";
        if(len==0) return ans;
        int index=0;
        ans=decode(s,index);
        return ans;
    }
    
    string decode(string s,int & index)   //每次递归时都及时更新index
    {
        string tmpAns="";
        int num=0;
        for(index;index<s.size();index++){
            if(s[index]>='0'&&s[index]<='9'){
                num=10*num+s[index]-'0';
            }
            else if(s[index]=='['){
                string tmpStr=decode(s,++index);
                while(--num) tmpAns+=tmpStr;  // add k times
                tmpAns+=tmpStr;      
            }
            else if(s[index]==']') return tmpAns;
            else tmpAns+=s[index];
        }
        return tmpAns;
    }
    
};
