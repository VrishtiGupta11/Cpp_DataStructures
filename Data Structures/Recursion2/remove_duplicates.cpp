#include <iostream>
#include <cstring>
using namespace std;

void RemoveDuplicates(char str[]) {
    if(strlen(str) == 0 || strlen(str) == 1) 
        return;
    RemoveDuplicates(str+1);
    if(str[0] == str[1]) {
        for(int i=1; i<=strlen(str); i++) 
            str[i] = str[i+1];
    }
}

int main() {
    char str[1000];
    cin >> str;
    RemoveDuplicates(str);
    cout << str;
}