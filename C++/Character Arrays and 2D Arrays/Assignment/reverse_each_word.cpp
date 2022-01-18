#include<iostream>
#include<cstring>
using namespace std;

void Reverse(char str[], int start, int end){
    char temp;
    for(int i=start, j=end; i<j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void ReverseEachWord(char str[]){
    int start = 0;
    for(int i=0; i<=strlen(str); i++){
        if(str[i] == ' ' || str[i] == '\0'){
            Reverse(str, start, i-1);
            start = i+1;
        }
    }
}

int main() {
    char str[100];
    cin.getline(str, 100);
    ReverseEachWord(str);
    cout<<str;
}