#include <iostream>
#include <vector>
#include <string>
#include "../trie.h"
using namespace std;

bool patternMatching(vector<string> str, string pattern) {
    Trie t;
    for(int i=0; i<str.size(); i++) {
        for(int j=0; j<str[i].length(); j++) {
            t.insertWord(str[i].substr(j));
        }
    }
    return t.search(pattern);
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
    string pattern; 
    cin >> pattern;
    cout << (patternMatching(str, pattern) ? "True" : "False") << endl;
}