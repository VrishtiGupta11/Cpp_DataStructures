#include <iostream>
#include "tree_node.h"
using namespace std;

void deleteTree(TreeNode<int>* root) {
    if(root == NULL)
        return;
    for(int i=0; i<root -> children.size(); i++) 
        deleteTree(root -> children[i]);
    delete root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    printTreeLevelWise(root);
    // deleteTree(root);
    delete root;
    cout << "After deleting: " << endl;
    printTreeLevelWise(root); 
}