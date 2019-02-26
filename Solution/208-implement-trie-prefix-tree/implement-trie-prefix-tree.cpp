// Implement a trie with insert, search, and startsWith methods.
//
// Example:
//
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true
//
//
// Note:
//
//
// 	You may assume that all inputs are consist of lowercase letters a-z.
// 	All inputs are guaranteed to be non-empty strings.
//
//


class TrieNode {
public:
    TrieNode* child [26];
    bool end_word;
    TrieNode() :end_word(false){
        for(auto& c : child) c=NULL;
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(char c : word){
            if(!tmp->child[c-'a']) tmp->child[c-'a'] = new TrieNode();
            tmp = tmp->child[c-'a'];
        }
        tmp->end_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;
        for(char c : word){
            if(!tmp->child[c-'a']) return false;
            tmp = tmp->child[c-'a'];
        }
        return tmp->end_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for(char c : prefix){
            if(!tmp->child[c-'a']) return false;
            tmp = tmp->child[c-'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
