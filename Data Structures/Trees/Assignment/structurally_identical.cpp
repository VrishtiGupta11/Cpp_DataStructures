#include <iostream>
#include "../tree_node.h"
using namespace std;

bool structurallyIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    bool identical = true;
    if(root1 -> data != root2 -> data)
        return false;
    if(root1 -> children.size() != root2 -> children.size())
        return false;
    for(int i=0; i<root1 -> children.size(); i++) 
        identical = identical && structurallyIdentical(root1 -> children[i], root2 -> children[i]);
    return identical;
}

int main() {
    TreeNode<int>* root1 = takeInputLevelWise<int>();
    TreeNode<int>* root2 = takeInputLevelWise<int>();
    cout << (structurallyIdentical(root1, root2) ? "True" : "False");
}