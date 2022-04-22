#include <iostream>
using namespace std;
#include "node.cpp"

int midElement(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    int* output = new int[testCasesCopy];

    while(testCases > 0) {
        Node* head = takeInput();
        output[testCasesCopy - testCases] = midElement(head);
        testCases--;
    }
    cout << endl;
    for(int i=0; i<testCasesCopy; i++) 
        cout << output[i] << endl;
}