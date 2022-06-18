#include <iostream>
#include "tree_node.h"
using namespace std;

int sumNodes(TreeNode<int>* root) {
    int sum = root -> data;
    for(int i=0; i<root -> children.size(); i++) {
        sum += sumNodes(root -> children[i]);
    }
    return sum;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout << sumNodes(root);
}