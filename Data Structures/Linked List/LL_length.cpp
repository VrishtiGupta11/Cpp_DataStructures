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

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    int* output = new int[testCasesCopy];
    while(testCases > 0) {
        Node* head = takeInput();
        output[testCasesCopy - testCases] = length(head);
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++)
        cout << output[i] << endl;
}