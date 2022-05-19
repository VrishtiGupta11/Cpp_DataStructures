#include <iostream>
using namespace std;
#include "queue_array.cpp"

int main() {
    Queue<int> q1;
    cout << "Is stack empty? " << (q1.isEmpty() ? "true" : "false") << endl;
    cout << "front element: " << q1.front() << endl;
    q1.enqueue(1);
    q1.enqueue(1);
    q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    

    cout << "front element: " << q1.front() << endl;
    cout << "Is stack empty? " << (q1.isEmpty() ? "true" : "false") << endl;
    q1.dequeue();
    cout << "Is stack empty? " << (q1.isEmpty() ? "true" : "false") << endl;
    cout << "Size: " << q1.size() << endl;
}