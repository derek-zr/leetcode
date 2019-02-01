// We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
//
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
//
// Return a list of all uncommon words. 
//
// You may return the list in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]
//
//
//
// Example 2:
//
//
// Input: A = "apple apple", B = "banana"
// Output: ["banana"]
//
//
//  
//
// Note:
//
//
// 	0 <= A.length <= 200
// 	0 <= B.length <= 200
// 	A and B both contain only spaces and lowercase letters.
//
//
//
//


class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string,int> counts;
        vector<string> ans;
        stringstream ss(A);   //stringstream构造和析构耗时较长
        while(ss>>A) counts[A]++;
        ss.clear();
        ss.str(B);            //清除流，重新绑定B
        while(ss>>B) counts[B]++;
        for(auto p:counts){
            if(p.second==1) ans.push_back(p.first);
        }
        return ans;
    }
};
