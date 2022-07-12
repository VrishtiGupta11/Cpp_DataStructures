#include <iostream>
#include "binary_tree_node.h"
using namespace std;

int countNodes(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return 0;
    int count = 1;
    if(root -> left != NULL)
        count += countNodes(root -> left);
    if(root -> right != NULL)
        count += countNodes(root -> right);
    return count;
}

int countNodes1(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return 0;
    return 1 + countNodes(root -> left) + countNodes(root -> right);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int count = countNodes(root);
    cout << count << endl;
}