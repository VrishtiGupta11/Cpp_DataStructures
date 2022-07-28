#include <iostream>
#include "../binary_tree_node.h"
using namespace std;

int helper(BinaryTreeNode<int>* root, int sum) {
    if(root == NULL)
        return 0;
    int rsum = helper(root -> right, sum);

    // Required previous value of root's data rather than updated value.
    int toBeReturned = root -> data + rsum;
    
    root -> data += rsum + sum;
    sum = root -> data;
    int lsum = helper(root -> left, sum);
    return lsum + toBeReturned;
}

void replaceWithSum(BinaryTreeNode<int>* root) {
    helper(root, 0);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    replaceWithSum(root);
    printTreeLevelWise(root);
}