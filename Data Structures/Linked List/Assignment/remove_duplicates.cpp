#include <iostream>
using namespace std;
#include "node.cpp"

Node* removeDuplicates(Node* head) {
    Node* temp1 = head;
    Node* temp2 = head -> next;
    if(temp1 == NULL || temp2 == NULL) 
        return head;
    while(temp2 != NULL) {
        if(temp1 -> data != temp2 -> data) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else {
            Node* toDelete = temp2;
            temp2 = temp2 -> next;
            temp1 -> next = temp2;
            delete toDelete;
        }
    }
    return head;
}

int main() {
    int testCases, testCasesCopy;
    cin >> testCases;
    testCasesCopy = testCases;
    Node** output = new Node*[testCasesCopy];

    while(testCases > 0) {
        Node* head = takeInput();
        output[testCasesCopy - testCases] = removeDuplicates(head);
        testCases--;
    }
    cout << endl;
    for(int i=0; i<testCasesCopy; i++)
        print(output[i]);
}