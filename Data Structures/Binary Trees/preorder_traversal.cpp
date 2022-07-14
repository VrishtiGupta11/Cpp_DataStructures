#include <iostream>
#include "binary_tree_node.h"
using namespace std;

void preorder(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    preorder(root);
}