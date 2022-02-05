#include <iostream>
#include <cstring>
using namespace std;

void ReplaceCharacters(char str[], char C1, char C2) {
    if(strlen(str) == 0)
        return;
    ReplaceCharacters(str+1, C1, C2);
    if(str[0] == C1)
        str[0] = C2;
}

int main() {
    char str[1000000], C1, C2;
    cin >> str >> C1 >> C2;
    ReplaceCharacters(str, C1, C2);
    cout << str;
}