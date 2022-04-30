#include <iostream>
using namespace std;
#include "node.cpp"

int nodeIndex(Node* head, int n) {
    if(head -> data == n)
        return 0;
    else if(head -> next == NULL)
        return -1;
    int smallAns = nodeIndex(head -> next, n);
    if(smallAns == -1)
        return -1;
    else
        return 1 + smallAns;
}

int main() {
    Node* head = takeInput();
    int number;
    cin >> number;
    int index;
    index = nodeIndex(head, number);
    cout << index;
}