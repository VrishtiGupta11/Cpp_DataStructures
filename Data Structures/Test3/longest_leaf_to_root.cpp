#include <iostream>
#include <vector>
#include <cmath>
#include "binary_tree_node.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return 0;
    int lh = height(root -> left);
    int rh = height(root -> right);
    return 1+max(lh, rh);
}

void helper(BinaryTreeNode<int>* root, vector<int> &output, int h, int k) {
    if(root == NULL) 
        return;
    output.push_back(root -> data);
    if(h == k) {
        for(int i=output.size()-1; i>=0; i--)
            cout << output[i] << endl;
        return;
    }
    helper(root -> left, output, h, k+1);
    if(h != k && root->left == NULL && root->right == NULL)
        output.pop_back();
    helper(root -> right, output, h, k+1);
}

void longestLeafToRoot(BinaryTreeNode<int>* root) {
    vector<int> output;
    int h = height(root);
    helper(root, output, h, 1);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    longestLeafToRoot(root);
}