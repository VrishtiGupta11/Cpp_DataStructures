#include <iostream>
using namespace std;

class Pen {
  int color;
  public:
    Pen() {}
    Pen(int color) {
        cout << updateColor(this->color);
    }
    int updateColor(int color) {
        this->color = color;
        return this->color;
    }
};

int main() {
    Pen* p = new Pen(9);
    return 0;
}