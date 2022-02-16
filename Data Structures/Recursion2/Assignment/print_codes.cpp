#include <iostream>
#include <string>
using namespace std;

void PrintCodes(string str, string output) {
    if(str.length() == 0) {
        cout << output << endl;
        return;
    }

    string ch1 = string(1, str[0] - '0' + 'a' - 1);
    PrintCodes(str.substr(1), output + ch1);
    int num = (str[0] - '0')*10 + str[1] - '0';
    if(num >= 10 && num <= 26) {
        string ch2 = string(1, num + 'a' - 1);
        PrintCodes(str.substr(2), output + ch2);
    }
}

int main() {
    string str;
    int outputSize;
    getline(cin, str);
    PrintCodes(str, "");
}