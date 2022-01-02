#include<iostream>
#include<typeinfo>
using namespace std;
int main(){
    int a = 10, b = 23, c=a+b;
    cout<<c<<endl;
    
    cout<<"Size of "<<typeid(c).name()<<" is "<<sizeof(c)<<endl;

    char d = 'x';
    cout<<d<<endl;

    cout<<"Size of "<<typeid(d).name()<<" is "<<sizeof(d)<<endl;

    float e = 12.5;
    cout<<e<<endl;

    cout<<"Size of "<<typeid(e).name()<<" is "<<sizeof(e)<<endl;

    double f = 11111.2;
    cout<<f<<endl;

    cout<<"Size of "<<typeid(f).name()<<" is "<<sizeof(f)<<endl;

    bool g = true;
    cout<<g<<endl;

    cout<<"Size of "<<typeid(g).name()<<" is "<<sizeof(g)<<endl;

    return 0;
}