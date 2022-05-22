#include <iostream>
using namespace std;
#include "dequeue.cpp"

int main() {
    Dequeue<int> d1;
    d1.insertFront(10);
    d1.insertFront(20);
    d1.insertRear(30);
    d1.insertRear(40);
    cout << "Size: " << d1.sizeN() << endl;
    cout << "Front: " << d1.getFront() << endl;
    cout << "Rear: " << d1.getRear() << endl;
    cout << d1.deleteFront() << endl;
    cout << d1.deleteRear() << endl;
    cout << d1.deleteRear() << endl;
    cout << d1.deleteRear() << endl;
    cout << d1.deleteFront() << endl;
    cout << "Size: " << d1.sizeN() << endl;
    cout << "Front: " << d1.getFront() << endl;
    cout << "Rear: " << d1.getRear() << endl;
}