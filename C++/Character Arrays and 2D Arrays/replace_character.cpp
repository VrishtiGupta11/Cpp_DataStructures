#include<iostream>
using namespace std;

void ReplaceCharacter(char str[], char c1, char c2){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == c1){
            str[i] = c2;
        }
    }
}

int main() {
    char str[100], c1, c2;
    cin>>str;
    cin>>c1>>c2;
    ReplaceCharacter(str, c1, c2);
    cout<<str;
}