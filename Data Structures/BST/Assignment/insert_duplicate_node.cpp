#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

void insertDuplicateNode(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    insertDuplicateNode(root -> left);
    insertDuplicateNode(root -> right);
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(root -> data);
    if(root -> left == NULL) 
        root -> left = newNode;
    else {
        newNode -> left = root -> left;
        root -> left = newNode;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    insertDuplicateNode(root);
    printTreeLevelWise(root);
}