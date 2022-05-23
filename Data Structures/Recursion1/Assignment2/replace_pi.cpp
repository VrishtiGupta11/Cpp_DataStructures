#include <iostream>
#include <cstring>
using namespace std;

void ReplacePI(char str[], int size) {
    if(size == 0 || size == 1) 
        return;
    ReplacePI(str+1, size-1);
    if(str[0] == 'p' && str[1] == 'i') {
        for(int i=strlen(str); i>=2; i--) 
            str[i+2] = str[i];
        str[0] = '3';
        str[1] = '.';
        str[2] = '1';
        str[3] = '4';
    }
}

int main() {
    char str[100];
    cin >> str;
    ReplacePI(str, strlen(str));
    cout << str;
}

// Using string
/*
#include <iostream>
#include <string>
using namespace std;

string RPR(string str) {
    if(str.length() == 0 || str.length() == 1) 
        return str;
    string ans = RPR(str.substr(1));
    if(str[0] == 'p' && str[1] == 'i') {
        str = "3.14" + ans.substr(1);
        return str;
    }
    return str[0] + ans;
}

int main() {
    string str;
    getline(cin, str);
    cout << RPR(str) << endl;

    return 0;
}
*/