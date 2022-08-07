#include <iostream>
#include <vector>
#include "../trie.h"
using namespace std;

int main() {
    Trie t;
    int N;
    cin >> N;
    // vector<string> str;
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        t.insertWord(str);
    }
    string pattern; 
    cin >> pattern;    
    t.autoComplete(pattern);
}