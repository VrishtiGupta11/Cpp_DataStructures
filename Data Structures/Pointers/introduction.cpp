#include<iostream>
using namespace std;

int main() {
    int i = 10;
    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    // int* p;  // Don't do this, initialize pointer either with NULL or with some known address.
    // int *p = NULL;  // Do this
    int* p = &i; // Or this
    cout<<p<<endl;
    cout<<*p<<endl;
    (*p)++; 
    cout<<*p<<endl;
    cout<<i<<endl;
}