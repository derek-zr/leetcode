// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (35.71%)
 * Total Accepted:    231.6K
 * Total Submissions: 648.5K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
       int Asize=a.size();
        int Bsize=b.size();
        string ans="";
        bool jinwei=false;
        for(int i=Asize-1,j=Bsize-1;i>=0||j>=0;i--,j--){
            char tmp1=0,tmp2=0;
            if (i<0||j<0){
                if (i<0)  {tmp1='0';tmp2=b[j];}
                else {tmp1=a[i];tmp2='0';}
            }
            else{
                tmp1=a[i];
                tmp2=b[j];}

            if(jinwei){
                if ((tmp1=='0')&&(tmp2=='0')) {ans+='1';jinwei=false;}
                else if ((tmp1=='1')&&(tmp2=='1')) {ans+='1',jinwei=true;}
                else {ans+='0';jinwei=true;}                
            }
            else{
                if ((tmp1=='1')&&(tmp2=='1')) {ans+='0';jinwei=true;}
                else if ((tmp1=='0')&&(tmp2=='0')) {ans+='0';jinwei=false;}
                else {ans+='1';jinwei=false;}
                }          
        //cout<<tmp1<<tmp2<<endl;
        }
        
        if(jinwei) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};

