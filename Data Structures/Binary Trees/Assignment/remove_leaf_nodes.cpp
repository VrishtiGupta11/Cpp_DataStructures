#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return NULL;
    if(root -> left == NULL && root -> right == NULL) 
        return NULL;
    BinaryTreeNode<int>* l = removeLeafNodes(root -> left);
    BinaryTreeNode<int>* r = removeLeafNodes(root -> right);
    root -> left = l;
    root -> right = r;
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    removeLeafNodes(root);
    printTreeLevelWise<int>(root);
}