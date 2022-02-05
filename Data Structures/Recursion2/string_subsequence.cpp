#include <iostream>
using namespace std;

int StringSubsequence(string str, string output[]) {
    if(str.size() == 0) {
        output[0] = " ";
        return 1;
    }
    int smallAns = StringSubsequence(str.substr(1), output);
    for(int i=0; i<smallAns; i++) {
        output[i+smallAns] = str[0] + output[i];
    }
    return 2*smallAns;
}  

int main() {
    string str, output[100];
    cin >> str;
    int N = StringSubsequence(str, output);
    for(int i=0; i<N; i++) {
        cout << output[i] << endl;
    }
}