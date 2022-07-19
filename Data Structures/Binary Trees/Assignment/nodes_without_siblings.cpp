#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

void noSiblingNodes(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    if(root -> left != NULL) {
        if(root -> right == NULL) 
            cout << root -> left -> data << " ";
    }
    else {
        if(root -> right != NULL) 
            cout << root -> right -> data << " ";
    }
    noSiblingNodes(root -> left);
    noSiblingNodes(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    noSiblingNodes(root);
}