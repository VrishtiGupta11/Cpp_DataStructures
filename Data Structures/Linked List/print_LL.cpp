#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* ptr = head;
    while(ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main() {
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);
    Node* head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);
}