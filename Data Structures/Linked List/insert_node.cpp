#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* takeInput() {
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int length(Node* head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int ithdata(Node* head, int i) {
    int len = length(head);
    if(i < len) {
        Node* temp = head;
        while(i>0) {
            temp = temp->next;
            i--;
        }
        return temp->data;
    }
    return -1;
}

Node* insertNode(Node* head, int i, int data) {
    Node* newNode = new Node(data);
    Node* temp = head;
    if(i == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(i-1 > 0 && temp != NULL) {
        temp = temp->next;
        i--;
    } 
    if(temp != NULL) {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}

int main() {
    Node* head = takeInput();
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
}