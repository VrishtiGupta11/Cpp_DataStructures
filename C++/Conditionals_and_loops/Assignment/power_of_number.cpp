#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int base, power;
    cin>>base>>power;
    int exp = pow(base, power);
    cout<<exp;
    return 0;
}