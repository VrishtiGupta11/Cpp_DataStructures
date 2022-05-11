#include <iostream>
using namespace std;
template <typename T, typename V>    // Specifying temporary datatype T and V

class Pair {
    T x;
    V y;
public:
    void setX(T x) {
        this -> x = x;
    }
    T getX() {
        return this -> x;
    }
    void setY(V y) {
        this -> y = y;
    }
    V getY() {
        return this -> y;
    }
};