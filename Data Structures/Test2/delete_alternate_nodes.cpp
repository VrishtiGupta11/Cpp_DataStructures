#include <iostream>
using namespace std;
#include "node.cpp"

void deleteAlternateNodes(Node* head) {
    Node* temp = head;
    while(temp != NULL && temp -> next != NULL) {
        Node* del = temp -> next;
        temp -> next = temp -> next -> next;
        delete del;
        temp = temp -> next;
    }
}

int main() {
    Node* head = takeInput();
    deleteAlternateNodes(head);
    print(head);
}