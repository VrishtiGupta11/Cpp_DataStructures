#include <iostream>
using namespace std;
#include "node.cpp"

Node* reverseLL(Node* head) {
    if(head == NULL || head -> next == NULL) 
        return head;
    Node* forward = NULL;
    Node* previous = NULL;
    while(head != NULL) {
        forward = head ->next;
        head -> next = previous;
        previous = head;
        head = forward;
    }
    head = previous;
    return head;
}

bool isPallindrome(Node* head) {
    Node* head2 = head;
    int len = length(head);
    for(int i=0; i<len/2; i++)
        head2 = head2 -> next;
    
    head2 = reverseLL(head2);
    while(head != NULL && head2 != NULL) {
        if(head -> data != head2 -> data) 
            return false;
        head = head -> next;
        head2 = head2 -> next;
    }
    return true;
}

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    bool* output = new bool[testCasesCopy];

    while(testCases > 0) {
        Node* head = takeInput();
        output[testCasesCopy - testCases] = isPallindrome(head);
        testCases--;
    }
    cout << endl;
    for(int i=0; i<testCasesCopy; i++) {
        if(output[i]) 
            cout << "True" << endl;
        else 
            cout << "False" << endl;
    }
}