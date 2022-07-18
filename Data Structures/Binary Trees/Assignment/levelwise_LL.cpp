#include <iostream>
#include <vector>
#include <queue>
#include "../binary_tree_node.h"
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

vector<Node*> levelWiseLinkedList(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    Node* head = NULL;
    Node* tail = NULL;
    vector<Node*> arr;
    while(q.size() != 0) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL) {
            arr.push_back(head);
            head = NULL;
            tail = NULL;
            if(q.size() != 0) 
                q.push(NULL);
        }
        else {
            Node* newNode = new Node(front -> data);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail -> next = newNode;
                tail = tail -> next;
            }
            if(front -> left != NULL)
                q.push(front -> left);
            if(front -> right != NULL)
                q.push(front -> right);
        }
    }
    return arr;
}

void printLLs(BinaryTreeNode<int>* root) {
    vector<Node*> arr = levelWiseLinkedList(root);
    for(int i=0; i<arr.size(); i++) {
        Node* temp = arr[i];
        while(temp != NULL) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    printLLs(root);
}