#include <iostream>
#include "../Binary Trees/binary_tree_node.h"
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

Node* sortedLL(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return NULL;
    Node* leftNode = sortedLL(root -> left);
    Node* head = new Node(root -> data);
    // cout << head -> data << " ";
    Node* rightNode = sortedLL(root -> right);
    Node* temp = leftNode;
    
    if(temp != NULL) {
        while(temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = head;
    }
    else 
        leftNode = head;
    head -> next = rightNode;
    return leftNode;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    Node* head = sortedLL(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
}