#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* root, int n1, int n2) {
    if(root == NULL)
        return NULL;
    if(root -> data == n1 || root -> data == n2)
        return root;
    BinaryTreeNode<int>* leftNode = lca(root -> left, n1, n2);
    BinaryTreeNode<int>* rightNode = lca(root -> right, n1, n2);
    if(leftNode == NULL && rightNode == NULL) 
        return NULL;
    else if(leftNode == NULL && rightNode != NULL) 
        return rightNode;
    else if(leftNode != NULL && rightNode == NULL)
        return leftNode;
    else if(leftNode != NULL && rightNode != NULL)
        return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int n1, n2;
    cin >> n1 >> n2;
    BinaryTreeNode<int>* node = lca(root, n1, n2);
    if(node == NULL)
        cout << -1;
    cout << node -> data;
}