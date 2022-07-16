#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

int nodesSum(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return 0;

    int ans = root -> data;
    ans += nodesSum(root -> left) + nodesSum(root -> right);
    return ans; 
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    cout << nodesSum(root) << endl;
}