#include <iostream>
#include "tree_node.h"
using namespace std;

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* maxNode = root;
    for(int i=0; i<root -> children.size(); i++) {
        TreeNode<int>* tempNode = maxDataNode(root -> children[i]);
        if(tempNode -> data > maxNode -> data)
            maxNode = tempNode;
    }
    return maxNode;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    TreeNode<int>* maxNode = maxDataNode(root);
    cout << maxNode -> data;
}