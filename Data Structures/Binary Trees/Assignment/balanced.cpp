#include <iostream>
#include <cmath>
#include "../binary_tree_node.h"
using namespace std;

// BruteForce -> n*n -> n*height

// Pair class
class Pair {
public:
    bool checkBal;
    int height;
};

Pair isBalanced(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair p;
        p.checkBal = true;
        p.height = 0;
        return p;
    }
    Pair p;
    Pair p1 = isBalanced(root -> left);
    Pair p2 = isBalanced(root -> right);
    if(abs(p1.height - p2.height) > 1)
        p.checkBal = false;
    else
        p.checkBal = p1.checkBal && p2.checkBal;
    p.height = max(1+p1.height, 1+p2.height);
    return p;
}

// No pair class just implement with height i.e. if height is -1 => False else True so here we will return integer instead of boolean
int balanced(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return 0;
    int lh = balanced(root -> left);
    int rh = balanced(root -> right);
    if(abs(lh - rh) > 1) 
        return -1;
    if(lh == -1 || rh == -1)
        return -1;
    return max(1+lh, 1+rh);
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    // int height = balanced(root);
    // if(height == -1) 
    //     cout << "False" << endl;
    // else
    //     cout << "True" << endl; 
    Pair p = isBalanced(root);
    cout << (p.checkBal ? "True" : "False");
}