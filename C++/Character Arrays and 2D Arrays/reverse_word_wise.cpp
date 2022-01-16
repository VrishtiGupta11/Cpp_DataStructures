#include<iostream>
using namespace std;

void Reverse(char str[], int start, int end){
    char temp;
    for(int i=start, j=end; i<j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void ReverseWordWise(char str[], int N){
    int start = 0;
    Reverse(str, 0, N-1);
    for(int i=0; i<=N; i++){
        if(str[i] == ' ' || str[i] == '\0'){
            Reverse(str, start, i-1);
            start = i+1;
        }
    }
}

int main() {
    char str[100];
    int len=0;
    cin.getline(str, 100);
    for(int i=0; str[i] != '\0'; i++){
        len++;
    }
    ReverseWordWise(str, len);
    cout<<str<<endl;
}