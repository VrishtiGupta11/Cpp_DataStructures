#include <iostream>
using namespace std;
#include "node.cpp"

Node* merge(Node* h1, Node* h2) {
    Node* fh = NULL;
    Node* ft = NULL;
    while(h1 != NULL && h2 != NULL) {
        if(h1 -> data < h2 -> data) {
            if(fh == NULL) {
                fh = h1;
                ft = h1;
                h1 = h1 -> next;
            }
            else {
                ft -> next = h1;
                ft = h1;
                h1 = h1 -> next;
            }
        }
        else {
            if(fh == NULL) {
                fh = h2;
                ft = h2;
                h2 = h2 -> next;
            }
            else {
                ft -> next = h2;
                ft = h2;
                h2 = h2 -> next;
            }
        }
    }
    while(h1 != NULL) {
        ft -> next = h1;
        ft = h1;
        h1 = h1 -> next;
    }
    while(h2 != NULL) {
        ft -> next = h2;
        ft = h2;
        h2 = h2 -> next;
    }
    return fh;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    Node* mid = midNode(head);
    Node* h2 = mid -> next;
    mid -> next = NULL;
    
    Node* h1 = mergeSort(head);
    h2 = mergeSort(h2);
    Node* fh = merge(h1, h2);
    return fh;
}

int main() {
    Node* head = takeInput();
    head = mergeSort(head);
    print(head);
}