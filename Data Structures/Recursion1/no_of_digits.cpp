#include<iostream>
using namespace std;

int digitsCount(int number) {
    if(number == 0)
        return 0;
    return 1+digitsCount(number/10);
}

int main() {
    int number;
    cin >> number;
    cout << digitsCount(number);
}