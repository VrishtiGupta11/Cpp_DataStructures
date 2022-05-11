#include <iostream>
using namespace std;
#include "pair_template.cpp"

int main() {
    Pair<int, Pair<double, char>> p1;
    Pair<double, char> p2;
    p2.setX(2.3);
    p2.setY('3');
    p1.setX(1);
    p1.setY(p2);
    cout << p1.getX() << " " << p1.getY().getX() << " " << p1.getY().getY() << endl;
}