#include <iostream>
#include "tree_node.h"
using namespace std;

TreeNode<int>* removeLeaf(TreeNode<int>* root) {
    if(root==NULL)
        return NULL;
    if(root->children.size()==0) {
        delete root;
        return NULL;
    }
    for(int i=0;i<root->children.size();i++) {
        TreeNode<int>* child=root->children[i];
        if(child->children.size()==0) {
            delete child;
            for(int j=i;j<root->children.size()-1;j++) {
                root->children[j]=root->children[j+1];
            }
            root->children.pop_back();
            i--;
        }
    }
    for(int i=0;i<root->children.size();i++){  //recursive call
        root->children[i]=removeLeaf(root->children[i]);
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout << endl;
    root = removeLeaf(root);
    printTreeLevelWise(root);
}