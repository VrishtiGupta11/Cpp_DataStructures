#include<iostream>
using namespace std;

int main() {
    int number, reverse = 0;
    cin>>number;
    while (number > 0)
    {
        reverse = reverse * 10 + (number%10);
        number /= 10;
    }
    cout<<reverse;
}