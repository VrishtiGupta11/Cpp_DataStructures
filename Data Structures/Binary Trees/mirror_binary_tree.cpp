#include <iostream>
#include "binary_tree_node.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return;
    BinaryTreeNode<int>* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;
    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    mirrorBinaryTree(root);
    printTreeLevelWise(root);
}