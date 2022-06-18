#include <iostream>
#include "tree_node.h"
using namespace std;

int treeHeight(TreeNode<int>* root) {
    int height = 1;
    for(int i=0; i<root -> children.size(); i++) {
        int temp = 1+treeHeight(root -> children[i]);
        if(temp > height) 
            height = temp;
    }
    return height;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout << treeHeight(root);
}