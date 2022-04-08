#include <iostream>
#include "fractions.cpp"
using namespace std;

int main() {
    Fractions f1(10, 2);
    Fractions f2(15, 4);
    Fractions const f3;  // Const objects can call const functions only.
    cout << f3.getNumerator() << " " << f3.getDenominator();
}