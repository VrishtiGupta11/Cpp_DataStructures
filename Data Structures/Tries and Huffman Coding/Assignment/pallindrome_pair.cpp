#include <iostream>
#include <vector>
#include "../trie.h"
using namespace std;

string reverse(string str) {
    string output = "";
    for(int i=str.length()-1; i>=0; i--) {
        output += str[i];
    }
    return output;
}

bool isPallindromePair(vector<string> str) {
    Trie t;
    for(int i=0; i<str.size(); i++) {
        t.insertWord(reverse(str[i]));
        if(t.searchWord(str[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<string> str;
    string s;
    for(int i=0; i<N; i++) {
        cin >> s;
        str.push_back(s);
    }
    
    cout << (isPallindromePair(str) ? "True" : "False") << endl;
} 