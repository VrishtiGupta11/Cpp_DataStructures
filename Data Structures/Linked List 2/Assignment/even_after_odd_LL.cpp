#include <iostream>
using namespace std;
#include "node.cpp"

Node* oddEven(Node* head) {
    Node *oddH = NULL, *evenH = NULL, *oddT = NULL, *evenT = NULL, *temp = head;
    while(temp != NULL) {
        if(temp -> data %2 != 0) {
            if(oddH == NULL) {
                oddH = temp;
                oddT = temp;
            }
            else {
                oddT -> next = temp;
                oddT = oddT -> next;
            }
        }
        else {
            if(evenH == NULL) {
                evenH = temp;
                evenT = temp;
            }
            else {
                evenT -> next = temp;
                evenT = evenT -> next;
            }
        }
        temp = temp -> next;
    }
    if(evenH != NULL) {
        evenT -> next = NULL;
    }
    if(oddH == NULL) {
        return evenH;
    }
    else {
        oddT -> next = evenH;
        return oddH;
    }
}

int main() {
    Node* head = takeInput();
    head = oddEven(head);
    print(head);
}