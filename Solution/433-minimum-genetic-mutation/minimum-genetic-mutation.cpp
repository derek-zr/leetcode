// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
//
// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
//
// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
//
// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
//
// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.
//
// Note:
//
//
// 	Starting point is assumed to be valid, so it might not be included in the bank.
// 	If multiple mutations are needed, all mutations during in the sequence must be valid.
// 	You may assume start and end string is not the same.
//
//
//  
//
// Example 1:
//
//
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
//
// return: 1
//
//
//  
//
// Example 2:
//
//
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
//
// return: 2
//
//
//  
//
// Example 3:
//
//
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
//
// return: 3
//
//
//  
//


class Solution {
public:
    //BFS
    int minMutation(string start, string end, vector<string>& bank) {
        if(bank.size()==0) return -1;
        vector<char> genes{'A','C','G','T'};
        unordered_set<string> valids(bank.begin(),bank.end());
        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        int muts = 0;
        while(!q.empty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                string tmp = q.front();
                q.pop();
                if(tmp==end) return muts;
                for(int j=0;j<tmp.size();j++){
                    char tmp_change = tmp[j];
                    for(char gene : genes){
                        tmp[j] = gene;
                        if(valids.count(tmp) && !visited.count(tmp)){
                            visited.insert(tmp);
                            q.push(tmp);
                        }
                    }
                    tmp[j] = tmp_change;  //还原
                }
            }
            muts++;
        }
        
        return -1;
    }
};
