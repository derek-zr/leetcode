// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


class WordDictionary {
public:
    struct TrieNode {
      public:
        TrieNode* child[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            //将子节点全部置为null
            for(auto &a : child) a = NULL;
        }
    };
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto &a : word) {
            int tmp = a-'a';
            if(!cur->child[tmp]) cur->child[tmp] = new TrieNode();
            cur = cur->child[tmp];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word,root,0);
    }
    
    bool searchHelper(string &word, TrieNode* cur,int i) {
        if(i == word.size()) return cur->isEnd;
        if(word[i] == '.') {
            //遍历每一个子节点
            for(auto &a : cur->child) {
                if(a && searchHelper(word,a,i+1)) return true;
            }
            return false;
        }
        else {
            int tmp = word[i]-'a';
            if(!cur->child[tmp]) return false;
            return searchHelper(word,cur->child[tmp],i+1);
        }
    }
    
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
