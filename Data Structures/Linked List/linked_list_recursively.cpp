#include <iostream>
#include "node.cpp"
using namespace std;

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

int lengthRecursively(Node* head) {
    if(head == NULL) 
        return 0;
    return 1+lengthRecursively(head->next);
}

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
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

Node* deleteRecursively(Node* head, int i) {
    if(head == NULL) 
        return head;
    if(i == 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    head -> next = deleteRecursively(head -> next, i-1);
    return head;
}

int elementIndex(Node* head, int data) {
    int index = 0;
    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == data)
            return index;
        temp = temp -> next;
        index++;
    }
    return -1;
} 

int main() {
    Node* head = takeInput();
    // Length
    // cout << "Length : " << lengthRecursively(head);
    
    // Insert a Node
    // int data, i;
    // cin >> data >> i;
    // head = insertRecursively(head, data, i);

    // Delete a Node
    // int i;
    // cin >> i;
    // head = deleteRecursively(head, i);
    // print(head);

    // Location of element
    int data, index;
    cin >> data;
    index = elementIndex(head, data);
    if(index == -1) 
        cout << "Element Not found" << endl;
    else
        cout << "Element found at Index " << index << endl;
}