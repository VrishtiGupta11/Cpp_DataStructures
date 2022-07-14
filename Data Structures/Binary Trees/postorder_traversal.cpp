#include <iostream>
#include "binary_tree_node.h"
using namespace std;

void postorder(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    postorder(root);
}