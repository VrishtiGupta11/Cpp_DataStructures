#include <iostream>
#include "binary_tree_node.h"
using namespace std;

int main() {
    // BinaryTreeNode<int>* root = takeInput<int>();
    // printTree(root);    
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    printTreeLevelWise(root);
}