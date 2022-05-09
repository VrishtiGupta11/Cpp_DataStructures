#include <iostream>
using namespace std;
#include "node.cpp"

Node* swapNode(Node* head, int i, int j) {
    Node *t1 = head, *t2 = head;
    int c1 = 0, c2 = 0;
    while(c1 < i-1 && c2 < j-1 && t1 != NULL && t2 != NULL) {
        t1 = t1 -> next;
        t2 = t2 -> next;
        c1++;
        c2++;
    }
    while(c1 < i-1 && t1 != NULL) {
        t1 = t1 -> next;
        c1++;
    }
    while(c2 < j-1 && t2 != NULL) {
        t2 = t2 -> next;
        c2++;
    }
    if(i == 0) {
        Node* temp = head;
        head = t2 -> next;
        t2 -> next = temp;

        temp = t1 -> next;
        t1 -> next = head -> next;
        head -> next = temp;
    }
    else {
        Node* temp = t1 -> next;
        t1 -> next = t2 -> next;
        t2 -> next = temp;

        temp = t1 -> next -> next;
        t1 -> next -> next = t2 -> next -> next;
        t2 -> next -> next = temp;
    }
    return head;
}

int main() {
    Node *head = takeInput();
    int i, j;
    cin >> i >> j;
    head = swapNode(head, i, j);
    print(head);
} 