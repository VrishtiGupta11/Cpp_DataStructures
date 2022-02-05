#include <iostream>
using namespace std;

void PrintKeypad(int num, string output) {
    string keypad[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if(num == 0) {
        cout << output << endl;
        return;
    }
    for(int i=0; i<keypad[num%10].size(); i++)
        PrintKeypad(num/10, keypad[num%10][i] + output);
}

int main() {
    int num;
    string output;
    cin >> num;
    PrintKeypad(num, output);
}