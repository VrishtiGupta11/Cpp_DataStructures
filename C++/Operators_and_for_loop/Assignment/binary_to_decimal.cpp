#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int binary_num, decimal_num = 0, i = 0;
    cin>>binary_num;
    while (binary_num > 0) {
        decimal_num += (binary_num % 10) * pow(2, i);
        i++;
        binary_num /= 10;
    }
    cout<<decimal_num<<endl;
    return 0;
}