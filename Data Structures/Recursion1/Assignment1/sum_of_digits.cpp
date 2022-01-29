#include <iostream>
using namespace std;

int DigitsSum(int number) {
    if(number == 0)
        return 0;
    int smallAns = DigitsSum(number/10);
    return smallAns + (number % 10);
}

int main() {
    int number;
    cin >> number;
    cout << DigitsSum(number);
}