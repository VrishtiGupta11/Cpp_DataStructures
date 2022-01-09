#include<iostream>
using namespace std;

void function(char a){
    cout<<a;
    a = sizeof(a);
}

int main() {
    char a = 1;
    function(a);
    cout<<a;
}