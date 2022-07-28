#include <iostream>
#include <climits>
#include <cmath>
#include "../binary_tree_node.h"
using namespace std;

// Approach 1 -> Bruteforce O(N^2)

// Approach 2 => O(N)
class Pair {
public:
    int largest;
    int smallest;
    int size;
};

Pair helper(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair p;
        p.largest = INT_MIN;
        p.smallest = INT_MAX;
        p.size = 0;
        return p;
    }
    // Post order traversal
    // Get values for the left subtree and right subtree for the current node.
    Pair p1 = helper(root -> left);
    Pair p2 = helper(root -> right);

    Pair p;
    // Checking whether BST or Not.
    if(root -> data > p1.largest && root -> data <= p2.smallest) {
        // It is a BST
        p.largest = max(root -> data, p2.largest);
        p.smallest = min(root -> data, p1.smallest);
        p.size = 1+p1.size+p2.size;  // Counting out all the nodes under root.
    }
    else {
        // Not a BST
        p.largest = INT_MAX;
        p.smallest = INT_MIN;
        p.size = max(p1.size, p2.size);
    }
    return p;
}

int largestBST(BinaryTreeNode<int>* root) {
    return helper(root).size;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    cout << largestBST(root) << endl;
}