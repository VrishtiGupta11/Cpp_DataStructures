#include <iostream>
using namespace std;
#include "stack_array.cpp"

int main() {
    Stack<char> s1;
    char element;
    cout << "Enter elements to push: " << endl;
    cin >> element;
    while(element != '0') {
        s1.push(element);
        cin >> element;
    }
    cout << "Size: " << s1.size() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Size: " << s1.size() << endl;
    cout << "Is stack empty? " << (s1.isEmpty() ? "Yes" : "No") << endl;
}