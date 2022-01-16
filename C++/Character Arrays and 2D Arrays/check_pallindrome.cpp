#include<iostream>
using namespace std;

bool isPalindrome(char str[], int N){
    for(int i=0, j=N-1; i < j; i++, j--){
        if(str[i] != str[j])
            return false;
    }
    return true;
}

int main() {
    char str[100];
    int N=0;
    cin>>str;
    for(int i=0; str[i] != '\0'; i++){
        N++;
    }
    if(isPalindrome(str, N))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}