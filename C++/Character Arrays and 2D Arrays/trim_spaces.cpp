#include<iostream>
using namespace std;

void TrimSpaces(char str[]){
    int i=0, j=0;
    char str1[100];
    while (str[i] != '\0') {
        if(str[i] == ' '){
            i++;
            continue;
        }
        str1[j++] = str[i++];
    }
    str1[j] = '\0';
    i = 0;
    for(; str1[i] != '\0'; i++) {
        str[i] = str1[i];
    }
    str[i] = '\0';
}

void TrimSpaces1(char str[]){
    int i=0, j=0;
    while (str[i] != '\0') {
        if(str[i] == ' '){
            i++;
            continue;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
}

int main() {
    char str[100];
    cin.getline(str, 100);
    TrimSpaces1(str);
    cout<<str<<endl;
}