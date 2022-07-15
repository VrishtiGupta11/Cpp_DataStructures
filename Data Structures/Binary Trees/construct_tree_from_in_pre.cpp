#include <iostream>
#include "binary_tree_node.h"
using namespace std;

BinaryTreeNode<int>* constructTree(int *inorder, int *preorder, int inS, int inE, int preS, int preE) {
    if(inS > inE || preS > preE) 
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preS]);
    int i=inS, len=0;
    while(inorder[i] != preorder[preS] && i<=inE) {
        len++;
        i++;
    }
    BinaryTreeNode<int>* leftNode = constructTree(inorder, preorder, inS, inS+len-1, preS+1, preS+len);
    BinaryTreeNode<int>* rightNode = constructTree(inorder, preorder, inS+len+1, inE, preS+len+1, preE);
    root -> left = leftNode;
    root -> right = rightNode;
    return root;
}

int main() {
    int N;
    cin >> N;
    int* inorder = new int[N];
    int* preorder = new int[N];
    for(int i=0; i<N; i++) 
        cin >> preorder[i];
    for(int i=0; i<N; i++) 
        cin >> inorder[i];
    
    BinaryTreeNode<int>* root = constructTree(inorder, preorder, 0, N-1, 0, N-1);
    printTreeLevelWise(root);
}