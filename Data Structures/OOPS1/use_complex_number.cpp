#include <iostream>
using namespace std;
#include "complex_number.cpp"

int main() {
    int real, img, choice;
    cin >> real >> img;
    ComplexNumber c1(real, img);
    
    cin >> real >> img;
    ComplexNumber c2(real, img);

    cin >> choice;
    if(choice == 1)
        c1.plus(c2);
    else if(choice == 2)
        c1.multiply(c2);
    
    c1.print();
}