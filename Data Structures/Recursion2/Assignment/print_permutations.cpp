#include <iostream>
using namespace std;

void PrintPermutations(string str, string output) {
    if(str.length() == 0) {
        cout << output << endl;
        return;
    }
    for(int i=0; i<str.length(); i++) {
        PrintPermutations(str.substr(0, i)+str.substr(i+1, str.length()), output+str[i]);
    }
}

int main() {
    string str;
    cin >> str;
    PrintPermutations(str, "");
}