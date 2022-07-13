#include <iostream>
#include "binary_tree_node.h"
using namespace std;

int max(int a, int b, int c) {
    return a>b ? ((a>c) ? a : c) : ((b>c) ? b : c); 
}

int treeHeight(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return 0;
    return max(1, 1+treeHeight(root -> left), 1+treeHeight(root -> right));
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int height = treeHeight(root);
    cout << height << endl;
}