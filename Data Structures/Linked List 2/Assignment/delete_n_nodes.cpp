#include <iostream>
using namespace std;
#include "node.cpp"

void deleteNnodes(Node* head, int M, int N) {
    Node *t1 = head, *t2 = head;
    while(t1 != NULL && t2 != NULL) {
        int c1=1, c2=1;
        while(c1 != M && t1 != NULL) {
            t1 = t1 -> next;
            c1++;
        }
        t2 = t1 -> next;
        while(c2 <= N && t2 != NULL) {
            Node* temp = t2;
            t2 = t2 -> next;
            delete temp;
            c2++;
        }
        t1 -> next = t2;
        t1 = t2;
    } 
    // delete t1, t2;
}

int main() {
    Node* head = takeInput();
    int M, N;
    cin >> M >> N;
    deleteNnodes(head, M, N);
    print(head);
}