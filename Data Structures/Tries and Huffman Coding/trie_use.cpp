#include <iostream>
#include "trie.h"
using namespace std;

int main() {
    Trie T;
    T.insertWord("and");
    T.insertWord("are");
    T.insertWord("dot");

    cout << (T.searchWord("and") ? "True" : "False") << endl;
    T.removeWord("and");
    cout << (T.searchWord("and") ? "True" : "False") << endl;
}