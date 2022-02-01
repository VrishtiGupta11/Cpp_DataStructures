#include <iostream>
#include <cstring>
using namespace std;

void PairStar(char str[]) {
    if(strlen(str) == 0 || strlen(str) == 1) 
        return;
    PairStar(str+1);
    if(str[0] == str[1]) {
        for(int i = strlen(str); i >= 0; i--)
            str[i+1] = str[i];
        str[1] = '*';
    }
}

int main() {
    char str[1000];
    cin >> str;
    PairStar(str);
    cout << str;
}