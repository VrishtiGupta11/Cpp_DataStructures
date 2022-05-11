#include <iostream>
using namespace std;
#include "pair_template.cpp"

int main() {
    Pair<int, double> p1;
    p1.setX(20);
    p1.setY(11.11);
    cout << p1.getX() << " " << p1.getY() << endl;
}