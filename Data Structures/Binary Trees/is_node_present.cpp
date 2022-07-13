#include <iostream>
#include "binary_tree_node.h"
using namespace std;

bool isNodePresent(BinaryTreeNode<int>* root, int X) {
    if(root == NULL) 
        return false;
    if(root -> data == X)
        return true || isNodePresent(root -> left, X) || isNodePresent(root -> right, X);
    else
        return false || isNodePresent(root -> left, X) || isNodePresent(root -> right, X);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int X;
    cin >> X;
    bool count = isNodePresent(root, X);
    cout << (count ? "True" : "False") << endl;
}