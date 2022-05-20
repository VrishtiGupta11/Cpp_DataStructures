#include <iostream>
using namespace std;
#include <queue>

int main() {
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    q1.push(50);
    q1.push(60);

    cout << "Front: " << q1.front() << endl;
    q1.pop();
    cout << "Front: " << q1.front() << endl;
    cout << "Size: " << q1.size() << endl;
    cout << "Is Empty: " << q1.empty() << endl;

    while(!q1.empty()) {
        cout << q1.front() << endl;
        q1.pop();
    }
}