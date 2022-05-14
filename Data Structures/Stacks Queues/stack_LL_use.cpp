#include <iostream>
using namespace std;
#include "stack_LL.cpp"

int main() {
    Stack<int> s1;
    cout << "Size: " << s1.size() << endl;
    cout << "Pop: " << s1.pop() << endl;
    cout << "is Empty: " << (s1.isEmpty() ? "Yes" : "No") << endl;
    s1.push(6);
    s1.push(11);
    s1.push(18);
    s1.push(19);
    s1.push(21);
    cout << "After Pushing: " << endl;
    cout << "Size: " << s1.size() << endl;
    cout << "is Empty: " << (s1.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top: " << s1.top() << endl;
}