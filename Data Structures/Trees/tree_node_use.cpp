#include <iostream>
#include "tree_node.h"
using namespace std;

int main() {
    // TreeNode<int>* root = takeInput<int>();
    // printTree(root);
    TreeNode<int>* root = takeInputLevelWise<int>();
    printTreeLevelWise(root);
}