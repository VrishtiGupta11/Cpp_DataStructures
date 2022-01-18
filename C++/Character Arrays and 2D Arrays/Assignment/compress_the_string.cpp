#include<iostream>
#include<cstring>
using namespace std;

void StringCompression(char str[]){
    int j=0, count = 0;
    for(int i=0; i<=strlen(str); i++){
        if(str[j] == str[i]){
            count++;
        }
        else{
            j++;
            if(count > 1){
                str[j] = 48+count;
                j++;
            }
            str[j] = str[i];
            count = 1;
        }
    }
    str[j] = '\0';
}

int main() {
    char str[100];
    cin>>str;
    StringCompression(str);
    cout<<str;
}