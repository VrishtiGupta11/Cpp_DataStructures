#include<iostream>
using namespace std;

void increment1(int **p){ // No changes will be reflected in main
    p++;
}

void increment2(int **p){ // Changes will be reflected in main
    (*p)++;
}

void increment3(int **p){ // Changes will be reflected in main
    (**p)++;
}

int main() {
    int i = 10;
    int *p = &i;

    int **p2 = &p;
    cout<<p2<<endl;
    cout<<&p<<endl;

    cout<<p<<endl;
    cout<<*p2<<endl;
    cout<<&i<<endl;

    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;
}