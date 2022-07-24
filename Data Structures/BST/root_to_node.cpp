#include <iostream>
#include <vector>
#include "../Binary Trees/binary_tree_node.h"
using namespace std;

bool helper(BinaryTreeNode<int>* root, int data, vector<int>* output) {
    if(root == NULL)
        return false;
    
    output->push_back(root -> data);
    if(root -> data == data) 
        return true;
    bool leftOutput = helper(root -> left, data, output);
    bool rightOutput = helper(root -> right, data, output);
    if(!leftOutput && !rightOutput) {
        output->pop_back();
        return false;
    }
    return true;
}

vector<int>* getRootToNode(BinaryTreeNode<int>* root, int data) {
    vector<int>* output = new vector<int>();
    helper(root, data, output);
    return output;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int data;
    cin >> data;
    vector<int>* output = getRootToNode(root, data);
    for(int i=0; i<output -> size(); i++) 
        cout << output->at(i) << " ";
}