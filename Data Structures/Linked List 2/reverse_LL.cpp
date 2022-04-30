#include <iostream>
using namespace std;
#include "node.cpp"

// Reverse LL using Recursion
Node* reverseLL(Node* head) {
    if(head == NULL || head -> next == NULL) 
        return head;
    Node* smallAns = reverseLL(head -> next);
    Node* temp = smallAns;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return smallAns;
}

int main() {
    Node* head = takeInput();
    head = reverseLL(head);
    print(head);
}