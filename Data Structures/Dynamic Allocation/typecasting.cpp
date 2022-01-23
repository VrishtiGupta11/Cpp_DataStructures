#include<iostream>
using namespace std;

int main() {
    int a = 65;
    float f = a;
    cout<<f<<endl;
    
    int *p = &a;
    float *pf = (float*)p;

    cout<<p<<endl;
    cout<<pf<<endl;

    cout<<*p<<endl;
    cout<<*pf<<endl;

    cout<<*(pf+1)<<endl;
    cout<<*(pf+2)<<endl;
    cout<<*(pf+3)<<endl;
}