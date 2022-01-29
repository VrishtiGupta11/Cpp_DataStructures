#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int StrToInt(char str[], int size) {
    if(str[0] == '\0')
        return 0;
    int smallAns = StrToInt(str+1, size-1);
    return smallAns + (str[0] - '0') * pow(10, size-1);
}

int main() {
    char str[10];
    cin >> str;
    cout << StrToInt(str, strlen(str));
}