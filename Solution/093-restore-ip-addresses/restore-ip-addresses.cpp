// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //典型的回溯法
        vector<string> ans;
        helper(s,4,"",ans);  //ip分为四个部分
        return ans;
    }
    
    void helper(string s,int cnt,string tmp,vector<string> &ans) {
        if(cnt == 0) {
            if(s.empty()){  //有四部分且全部字符串都用上
                tmp=tmp.substr(0,tmp.size()-1);  //去掉最后一个.
                ans.push_back(tmp);
            }
        }
        else{
        //遍历
        for(int i = 1; i <= 3; ++i) {  //ip最长为三位
            if(s.size()>=i && isValid(s.substr(0,i))) {
                helper(s.substr(i),cnt-1,tmp+s.substr(0,i)+".",ans);
            }
        }
        }
    }
    
    bool isValid(string s) {
        //00这种ip地址不合法
        if(s.empty() || s.size()>3 || (s.size()>1 && s[0]=='0')) return false;
        int num = stoi(s);
        return num <= 255 && num >= 0;  //在0-255之间
    }
};
