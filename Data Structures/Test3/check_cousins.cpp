#include <iostream>
#include <vector>
#include "binary_tree_node.h"
using namespace std;

void helper(BinaryTreeNode<int>* root, int p, int q, int k, vector<int> &output) {
    if(root == NULL) 
        return;
    if(root->data == p || root->data == q)
        output.push_back(k);
    helper(root->left, p, q, k+1, output);
    helper(root->right, p, q, k+1, output);
}

bool checkCousins(BinaryTreeNode<int>* root, int p, int q) {
    vector<int> output;
    helper(root, p, q, 0, output);
    return (output[0] == output[1]) ? true : false;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int p, q;
    cin >> p >> q;
    bool ans = checkCousins(root, p, q);
    cout << (ans ? "true" : "false") << endl;
}