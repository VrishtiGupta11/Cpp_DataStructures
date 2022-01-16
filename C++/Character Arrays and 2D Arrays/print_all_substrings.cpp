#include<iostream>
using namespace std;

void PrintSubstrings(char input[]){
    for(int i=0; input[i] != '\0'; i++){
        for(int j=i; input[j] != '\0'; j++){
            for(int k=i; k<=j; k++){
                cout<<input[k];
            }
            cout<<endl;
        }
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    PrintSubstrings(input);
}