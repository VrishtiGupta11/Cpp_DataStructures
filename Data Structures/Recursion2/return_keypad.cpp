#include <iostream>
using namespace std;

int ReturnKeypad(int num, string output[]) {
    string str[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string temp[100];
    if(num == 0 || num == 1) {
        return 1;
    }
    int smallAns = ReturnKeypad(num/10, output);
    
    for(int i=0; i<str[num%10].length(); i++) {
        for(int j=0; j<smallAns; j++)
            temp[j+(i*smallAns)] = output[j]+str[num%10][i];
    }
    for(int i=0; i<str[num%10].size()*smallAns; i++)
        output[i] = temp[i];
    
    return str[num%10].size()*smallAns;
}

int main() {
    int number, N;
    string output[100];
    cin >> number;
    N = ReturnKeypad(number, output);
    for(int i=0; i<N; i++) {
        cout << output[i] << endl;
    }
}