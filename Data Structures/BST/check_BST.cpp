#include <iostream>
#include <climits>
#include <cmath>
#include "../Binary Trees/binary_tree_node.h"
using namespace std;

// Approach 1 => complexity - O(N^2)
int minimum(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return INT_MAX;
    return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
}

int maximum(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return INT_MIN;
    return max(root -> data, max(maximum(root -> left), maximum(root -> right)));
}

bool checkBinarySearchTree(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return true;
    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);
    bool output = root -> data > leftMax && root -> data < rightMin && checkBinarySearchTree(root -> left) && checkBinarySearchTree(root -> right); 
    return output;
}

// Approach 2 => Complexity - O(N)
bool helper(BinaryTreeNode<int>* root, int minimum, int maximum) {
    if(root == NULL)
        return true;
    // bool output = true;
    if(root -> data > minimum && root -> data < maximum) {
        bool output = helper(root -> left, minimum, root -> data) && helper(root -> right, root -> data, maximum);
        return output;
    } 
    else 
        return false;
}

bool checkBST(BinaryTreeNode<int>* root) {
    return helper(root, INT_MIN, INT_MAX);
}

// Approach 3 => Using class and returning bool isBST, min, max  =>  Complexity - O(N)

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    // cout << (checkBinarySearchTree(root) ? "True" : "False"); 
    cout << (checkBST(root) ? "True" : "False"); 
}