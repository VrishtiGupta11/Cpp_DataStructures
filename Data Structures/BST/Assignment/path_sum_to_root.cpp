#include <iostream>
#include <vector>
#include "../binary_tree_node.h"
using namespace std;

void pathSum(BinaryTreeNode<int>* root, int k, vector<int> output) {
    if(root == NULL)
        return;
    if(root -> left == NULL && root -> right == NULL) {
        if(k == root -> data) {
            output.push_back(root -> data);
            for(int i=0; i<output.size(); i++) 
                cout << output[i] << " ";
            cout << endl;
        }
        return;
    }
    output.push_back(root -> data);
    pathSum(root -> left, k - root -> data, output);
    pathSum(root -> right, k - root -> data, output);
    output.pop_back();
}

void pathSum(BinaryTreeNode<int>* root, int k) {
    vector<int> output;
    pathSum(root, k, output);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int k;
    cin >> k;
    pathSum(root, k);
}