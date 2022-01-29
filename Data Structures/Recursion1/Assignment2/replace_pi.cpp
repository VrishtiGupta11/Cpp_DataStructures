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