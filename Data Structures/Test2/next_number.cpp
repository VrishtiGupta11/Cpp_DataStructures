#include <iostream>
using namespace std;
#include "node.cpp"

Node* reverseLL(Node* head) {
    Node* previous = NULL;
    Node* forw = NULL;
    while(head != NULL) {
        forw = head -> next;
        head -> next = previous;
        previous = head;
        head = forw;
    }
    head = previous;
    return head;
}

Node* nextNumber(Node* head) {
    head = reverseLL(head);
    Node* temp = head;
    if(temp -> data != 9)
        temp -> data += 1;
    else {
        while(temp -> data == 9) {
            temp -> data = 0;
            if(temp -> next != NULL)
                temp = temp -> next;
        }
        if(temp -> next == NULL) {
            Node* newNode = new Node(1);
            temp -> next = newNode;
        }
        else 
            temp -> data += 1;
    }
    
    head = reverseLL(head);
    return head;
}

int main() {
    Node* head = takeInput();
    head = nextNumber(head);
    print(head);
}