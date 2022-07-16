#include <iostream>
#include "binary_tree_node.h"
using namespace std;

BinaryTreeNode<int>* constructTree(int *inorder, int *postorder, int inS, int inE, int postS, int postE) {
    if(inS > inE || postS > postE) 
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postE]);
    int i=inS, len=0;
    while(inorder[i] != postorder[postE]) {
        len++;
        i++;
    }
    root -> left = constructTree(inorder, postorder, inS, inS+len-1, postS, postS+len-1);
    root -> right = constructTree(inorder, postorder, inS+len+1, inE, postS+len, postE-1);
    return root;
}

int main() {
    int N;
    cin >> N;
    int* inorder = new int[N];
    int* postorder = new int[N];
    for(int i=0; i<N; i++) 
        cin >> postorder[i];
    for(int i=0; i<N; i++) 
        cin >> inorder[i];
    
    BinaryTreeNode<int>* root = constructTree(inorder, postorder, 0, N-1, 0, N-1);
    printTreeLevelWise(root);
}