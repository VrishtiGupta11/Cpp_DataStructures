#include <iostream>
using namespace std;
#include <queue>

queue<int> reverseQueue(queue<int> q1) {
    if(q1.size() == 0 || q1.size() == 1) 
        return q1;
    int element = q1.front();
    q1.pop();
    q1 = reverseQueue(q1);
    q1.push(element);
    return q1;
}

int main() {
    queue<int> q1;
    int N, element;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> element;
        q1.push(element);
    }
    q1 = reverseQueue(q1);
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
}