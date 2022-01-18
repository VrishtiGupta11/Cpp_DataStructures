#include<iostream>
#include<cstring>
using namespace std;

char HighestOccuringCharacter(char str[]){
    int frequency[26] = {0}, maxInd = 0;
    for(int i=0; i<strlen(str); i++){
        frequency[str[i] - 'a']++;
    }
    for(int i=1; i<26; i++)
        if(frequency[i] > frequency[maxInd])
            maxInd = i;
    return (maxInd + 'a');
}

int main() {
    char str[100];
    cin>>str;
    cout<<HighestOccuringCharacter(str);
}