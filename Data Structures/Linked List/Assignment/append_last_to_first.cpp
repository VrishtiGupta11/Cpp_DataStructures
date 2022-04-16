#include <iostream>
using namespace std;
#include "node.cpp"

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

// Append Last N nodes to first
Node* appendToFirst(Node* head, int N) {
    Node* temp = head;
    Node* tail = head;
    int len = length(head);

    for(int i=0; i < len - N - 1; i++) {
        temp = temp -> next;
        tail = tail -> next;
    }

    while(tail -> next != NULL) {
        tail = tail -> next;
    }

    tail -> next = head;
    head = temp -> next;
    temp -> next = NULL;

    return head;
}

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    Node** output = new Node*[testCasesCopy];

    while(testCases > 0) {
        Node* head = takeInput();
        int N;
        cin >> N;
        output[testCasesCopy - testCases] = appendToFirst(head, N);
        testCases--;
    }
    cout << endl;
    for(int i=0; i<testCasesCopy; i++)
        print(output[i]);
}