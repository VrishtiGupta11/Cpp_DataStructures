#include <iostream>
#include <vector>
#include "../Binary Trees/binary_tree_node.h"
using namespace std;

BinaryTreeNode<int>* constructBST(int *arr, int si, int ei) {
    if(si > ei) 
        return NULL;
    int mid = (si + ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int>* leftNode = constructBST(arr, si, mid-1);
    BinaryTreeNode<int>* rightNode = constructBST(arr, mid+1, ei);
    root -> left = leftNode;
    root -> right = rightNode;
    return root;
}

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) 
        cin >> arr[i];

    BinaryTreeNode<int>* root = constructBST(arr, 0, N-1);
    printTreeLevelWise<int>(root);
}