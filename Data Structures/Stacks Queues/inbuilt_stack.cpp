#include <iostream>
using namespace std;
#include <stack>

int main() {
    stack<int> s1;
    s1.push(6);
    cout << "Size: " << s1.size() << endl;
    cout << "Top: " << s1.top() << endl;
    s1.pop();
    cout << "Size: " << s1.size() << endl;
    cout << "Top: " << s1.top() << endl;
}