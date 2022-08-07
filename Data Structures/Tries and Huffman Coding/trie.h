#include <iostream>
#include "trie_node.h"
using namespace std;

class Trie {
    TrieNode* root;

    void insertWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertWord(child, word.substr(1));
    }

    bool searchWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            if(root -> isTerminal)
                return true;
            else
                return false;
        }
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            return searchWord(root -> children[index], word.substr(1));
        }
        else
            return false;
    }

    bool search(TrieNode* root, string word) {
        if(word.size() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        if(root -> children[index] != NULL) {
            return search(root -> children[index], word.substr(1));
        }
        else
            return false;
    }

    void removeWord(TrieNode* root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            return;  // Word not found
        }
        
        removeWord(child, word.substr(1));

        // Remove child if it is useless
        if(child -> isTerminal == false) {
            for(int i=0; i<26; i++) {
                if(child -> children[i] != NULL) 
                    return;
            }
            delete child;
            root -> children[index] = NULL;
        }
    }

    void allPossibleNodes(TrieNode* root, string output, string word) {
        if(root->isTerminal) 
            cout << word + output << endl;
        for(int i=0; i<26; i++) {
            if(root -> children[i] != NULL) 
                allPossibleNodes(root -> children[i], output+root -> children[i] -> data, word);
        }
    }

    void autoComplete(TrieNode* root, string str, string word) {
        if(str.size() == 0) {
            allPossibleNodes(root, "", word);
            return;
        }
        int index = str[0] - 'a';
        if(root -> children[index] != NULL) {
            autoComplete(root -> children[index], str.substr(1), word);
        }
        else {
            cout << "No word found :)" << endl;
            return;
        }
    }

public:
    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
        insertWord(root, word);
    }

    // if looking to find Exact same word
    bool searchWord(string word) {
        return searchWord(root, word);
    }

    void removeWord(string word) {
        removeWord(root, word);
    }

    // Search function -> if looking to find pattern
    bool search(string word) {
        return search(root, word);
    }

    // Autocomplete
    void autoComplete(string word) {
        autoComplete(root, word, word);
    }
};
