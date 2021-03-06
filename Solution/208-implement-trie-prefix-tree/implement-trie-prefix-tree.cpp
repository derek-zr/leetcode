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
    TrieNode* children[26];
    bool word_end;
    TrieNode() : word_end(false) {
        for (int i = 0; i < 26; ++i) children[i] = NULL;
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
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c-'a'])  cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->word_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c-'a'])  return false;
            cur = cur->children[c-'a'];
        }
        return cur->word_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children[c-'a'])  return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
