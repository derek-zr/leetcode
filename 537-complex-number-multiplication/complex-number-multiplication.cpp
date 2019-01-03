//
// Given two strings representing two complex numbers.
//
//
// You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//
//
// Example 1:
//
// Input: "1+1i", "1+1i"
// Output: "0+2i"
// Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
//
//
//
// Example 2:
//
// Input: "1+-1i", "1+-1i"
// Output: "0+-2i"
// Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
//
//
//
// Note:
//
// The input strings will not have extra blank.
// The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
//
//


class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int realA,realB,imgA,imgB;
        //stringstream ans;
        string strAr,strAi,strBr,strBi;
        strAr=a.substr(0,a.find('+'));
        strAi=a.substr(a.find('+')+1,a.find('i')-a.find('+')-1);
        strBr=b.substr(0,b.find('+'));
        strBi=b.substr(b.find('+')+1,b.find('i')-b.find('+')-1);
        realA=stoi(strAr);
        imgA=stoi(strAi);
        realB=stoi(strBr);
        imgB=stoi(strBi);
        int real,img;
        real=realA*realB-imgA*imgB;
        img=realA*imgB+realB*imgA;
        string ans=to_string(real)+"+"+to_string(img)+"i";
        return ans;
        /*ans<<real<<"+"<<img<<"i";
        return ans.str();*/
    }
};
