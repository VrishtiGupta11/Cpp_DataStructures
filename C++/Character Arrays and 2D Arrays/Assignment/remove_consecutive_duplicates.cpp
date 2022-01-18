#include<iostream>
#include<cstring>
using namespace std;

void RemoveConsecutiveDuplicates(char str[]){
    int nextUnique=1, i=1;
    char element = str[0];
    while(i < strlen(str)){
        if(str[i] == element)
            i++;
        else{
            element = str[i];
            str[nextUnique++] = str[i++];
        }
    }
    str[nextUnique] = '\0';
}

int main() {
    char str[100];
    cin>>str;
    RemoveConsecutiveDuplicates(str);
    cout<<str;
}