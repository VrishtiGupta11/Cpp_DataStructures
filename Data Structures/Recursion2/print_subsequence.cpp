#include <iostream>
using namespace std;

void PrintSubsequence(string str, string output) {
    if(str.size() == 0) {
        cout << output << endl;
        return;
    }
    PrintSubsequence(str.substr(1), output);
    PrintSubsequence(str.substr(1), output + str[0]);
}

int main() {
    string str, output;
    cin >> str;
    PrintSubsequence(str, output);
}