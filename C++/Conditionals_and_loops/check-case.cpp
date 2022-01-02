#include<iostream>
using namespace std;

int main(){
    char c;
    cout<<"Enter Character: ";
    cin>>c;
    if(c >= 'A' && c <= 'Z'){
        cout<<"1\n";
    }
    else if (c >= 'a' && c <= 'z'){
        cout<<"0\n";
    }
    else{
        cout<<"-1\n";
    }
    return 0;    
}