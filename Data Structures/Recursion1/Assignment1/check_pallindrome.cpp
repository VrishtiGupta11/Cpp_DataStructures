#include <iostream>
#include <cstring>
using namespace std;

bool isPallindrome(char str[], int N) {
    if(N == 0 || N == 1)
        return true;
    if(str[0] != str[N-1])
        return false;
    bool smallAns = isPallindrome(str+1, N-2);
    return smallAns;
}

int main() {
    char* str = new char[1000];
    cin >> str;
    bool output = isPallindrome(str, strlen(str));
    if(output)
        cout << "true";
    else
        cout << "false";
}