#include <iostream>
#include "tree_node.h"
using namespace std;

int countLeafNodes(TreeNode<int>* root) {
    if(root == NULL)
        return 0;
    if(root -> children.size() == 0)
        return 1;
    int count = 0;
    for(int i=0; i<root -> children.size(); i++) {
        count = count + countLeafNodes(root -> children[i]);
    }
    return count;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout << countLeafNodes(root);
}