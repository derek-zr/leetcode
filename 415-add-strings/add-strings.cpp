// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1==0) return num2;
        if(len2==0) return num1;
        int i,j;
        bool jinwei = false;
        //短的字串补零
        if(len1>len2){
            i=j=len1-1;
            int tmp =len1-len2;
            while(tmp){num2="0"+num2;tmp--;}
        }
        else{
            i=j=len2-1;
            int tmp =len2-len1;
            while(tmp){num1="0"+num1;tmp--;}
        }
        for(i,j;i>=0 && j>=0;i--,j--){
            int tmp = int(num1[i]-'0')+int(num2[j]-'0')+int(jinwei);
            if(tmp >=10) {jinwei=true;ans+=(tmp%10 +'0');}
            else {jinwei=false;ans+=(tmp+'0');}
        }
        
        if(jinwei) ans+='1';
        //cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
