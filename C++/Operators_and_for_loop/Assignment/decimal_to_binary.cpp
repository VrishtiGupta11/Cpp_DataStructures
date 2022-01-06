// Decimal to Binary

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int decimal_num, i=0;
    cin>>decimal_num;
    long int binary_num = 0;
    while (decimal_num != 0) {
        binary_num += ((decimal_num % 2) * pow(10, i));
        // cout<<(decimal_num % 2)<<"*"<<pow(10, i)<<endl;
        // cout<<binary_num<<endl;
        decimal_num /= 2;
        i++;
    }
    cout<<binary_num<<endl;
    return 0;
}