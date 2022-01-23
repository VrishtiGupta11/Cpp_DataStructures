#include<iostream>
using namespace std;

void increment1(int *p){
    p++;
}

void increment2(int *p){
    (*p)++;
}

int main() {
    int i = 0;
    int *p = &i;
    
    cout<<p<<endl;
    increment1(p);
    cout<<p<<endl;

    cout<<*p<<endl;
    increment2(p);
    cout<<*p<<endl;
}