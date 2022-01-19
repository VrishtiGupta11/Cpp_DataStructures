#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

void MinLengthWord(char str[]){
    int i=0, count = 0, minLen = INT_MAX;
    char word[50], minStr[50];
    while(i < strlen(str)){
        if(str[i] == ' '){
            if(count+1 < minLen){
                minLen = count+1;   
                strcpy(minStr, word);
                minStr[count] = '\0';
            }
            count = 0;
            i++;
        }
        else
            word[count++] = str[i++];
    }
    cout<<minStr<<endl;
}

int main() {
    char str[100];
    cin.getline(str, 100);
    MinLengthWord(str);
}