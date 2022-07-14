#include <iostream>
#include "binary_tree_node.h"
using namespace std;

void inorder(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    inorder(root);
}