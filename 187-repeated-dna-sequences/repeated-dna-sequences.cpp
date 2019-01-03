// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
//
// Example:
//
//
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//
// Output: ["AAAAACCCCC", "CCCCCAAAAA"]
//
//


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size()<=10) return ans;
        set<int> seqs;
        vector<int> map(26,0);
        map['A'-'A'] = 0; //00
        map['C'-'A'] = 1; //01 
        map['G'-'A'] = 2; //10
        map['T'-'A'] = 3; //11
        
        for(int i=0;i<=s.size()-10;i++){
            int seq=0;
            for(int j=i;j<i+10;j++){
                seq <<= 2;
                seq |= map[s[j]-'A'];
            }
            //cout<<seq<<endl;
            if(seqs.find(seq)!=seqs.end()){
                string tmp = s.substr(i,10);
                if(find(ans.begin(),ans.end(),tmp)==ans.end()){   //防止重复插入
                    ans.push_back(tmp);      
                }
            }
            else seqs.insert(seq);
        }
        return ans;
    }
};
