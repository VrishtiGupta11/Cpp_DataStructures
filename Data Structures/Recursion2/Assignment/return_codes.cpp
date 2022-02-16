#include <iostream>
#include <string>
using namespace std;

int ReturnCodes(string str, string output[]) {
    if(str.length() == 0) {
        output[0] = "";
        return 1;   // Did Mistake
    }
    if(str.length() == 1) {
        output[0] = str[0] - '0' + 'a' - 1;
        return 1;
    }
    int smallAns1 = ReturnCodes(str.substr(1), output);
    for(int i=0; i<smallAns1; i++) {
        output[i] = string(1, str[0] - '0' + 'a' - 1) + output[i];      // string class has a constructor that allows us to specify size of string as first parameter and character to be filled in given size as second parameter.
    }
    
    int num = (str[0] - '0')*10 + (str[1] - '0'); // Did Mistake
    int smallAns2=0;
    if(num >= 10 && num <= 26) {
        smallAns2 = ReturnCodes(str.substr(2), output+smallAns1);
    }
    for(int i=0; i<smallAns2; i++)
        output[i + smallAns1] = string(1, num + 'a' - 1) + output[i + smallAns1];
    return smallAns1+smallAns2;
}

int main() {
    string str, output[100];
    int outputSize;
    getline(cin, str);
    outputSize = ReturnCodes(str, output);
    for(int i=0; i<outputSize; i++)
        cout << output[i] << endl;
}