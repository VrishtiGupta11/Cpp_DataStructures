#include <iostream>
#include "../Binary Trees/binary_tree_node.h"
using namespace std;

void printRange(BinaryTreeNode<int>* root, int min, int max) {
    if(root == NULL)
        return;
    if(max < root -> data || min < root -> data)
        printRange(root -> left, min, max);
    if(root -> data >= min && root -> data <= max)
        cout << root -> data << " ";
    if(min > root -> data || max > root -> data)
        printRange(root -> right, min, max);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int min, max;
    cin >> min;
    cin >> max;
    printRange(root, min, max);
}