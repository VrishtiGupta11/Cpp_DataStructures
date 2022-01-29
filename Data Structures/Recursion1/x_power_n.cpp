#include<iostream>
using namespace std;

int BasePower(int base, int power) {
    if(power == 0) {
        return 1;
    }
    return base*BasePower(base, power-1);
}

int main() {
    int base, power, output;
    cin >> base >> power;

    output = BasePower(base, power);
    cout << output <<endl;
}