#include<iostream>
#include<cstring>
using namespace std;

void RemoveCharacter(char str[], char X){
    int i=0, j=0;
    while(i < strlen(str)) {
        if(str[i] == X)
            i++;
        else{
            str[j++] = str[i++];
        }
    }
    str[j] = '\0';
}

int main() {
    char str[100], X;
    cin>>str>>X;
    RemoveCharacter(str, X);
    cout<<str;
}