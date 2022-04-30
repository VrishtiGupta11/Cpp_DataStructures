#include <iostream>
using namespace std;
#include "node.cpp"

// Just printing the reversed Linked List
void printReverseLL(Node* head) {
    if(head == NULL)
        return;
    printReverseLL(head -> next);
    cout << head -> data << " ";
}

// Actually reversing the original Linked List using Iteration
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

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    // Node** output = new Node*[testCasesCopy];

    while(testCases > 0) {
        Node* head = takeInput();
        // output[testCasesCopy - testCases] = reverseLL(head);
        printReverseLL(head);
        testCases--;
    }
    cout << endl;
    // for(int i=0; i<testCasesCopy; i++)
    //     print(output[i]);
}