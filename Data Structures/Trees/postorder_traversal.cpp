#include <iostream>
#include "tree_node.h"
using namespace std;

void postorder(TreeNode<int>* root) {
    if(root == NULL)
        return;
    for(int i=0; i<root -> children.size(); i++) 
        postorder(root -> children[i]);
    cout << root -> data << " ";
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    postorder(root);
}