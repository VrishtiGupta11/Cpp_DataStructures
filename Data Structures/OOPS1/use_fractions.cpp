#include <iostream>
using namespace std;
#include "fractions.cpp"

int main() {
    Fractions f1(3, 5);
    Fractions f2(2, 3);
    f1.addFractions(f2);
    f1.display();
}