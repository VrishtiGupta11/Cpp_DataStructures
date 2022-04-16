#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
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
    cout << endl;
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

Node* insertRecursively(Node* head, int data, int i) {
    if(head == NULL)
        return head;
    if(i == 0) {
        Node* newNode = new Node(data);
        newNode ->next = head;
        head = newNode;
        return head;
    }
    head -> next = insertRecursively(head -> next, data, i-1);
    return head;
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