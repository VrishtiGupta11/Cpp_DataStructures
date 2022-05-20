#include <iostream>
using namespace std;
#include <stack>

stack<int> reverseStack(stack<int> s1) {
    stack<int> s2;
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    return s2;
}

int main() {
    stack<int> s1, s2;
    int N, element;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> element;
        s1.push(element);
    }
    s2 = reverseStack(s1);
    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
}