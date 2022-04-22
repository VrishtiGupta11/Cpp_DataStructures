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

int main() {
    Node* h1;
    Node* h2;
    Node* fh;
    h1 = takeInput();
    h2 = takeInput();
    fh = merge(h1, h2);
    print(fh);
}