// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
//
// For example, with A = "abcd" and B = "cdabcdab".
//
// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
//
// Note:
// The length of A and B will be between 1 and 10000.
//


class Solution {
public:
    //len(B)/len(A)+2次，如果还没找到，则说明不可能有了
    int repeatedStringMatch(string A, string B) {
        string tmp = A;
        int cnts = 1;
        for(int i=0;i<B.size()/A.size()+2;i++){
            if(tmp.find(B)!=string::npos) return cnts;
            tmp += A;
            cnts++;
        }
        return -1;
    }
};
