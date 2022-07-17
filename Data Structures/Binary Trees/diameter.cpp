#include <iostream>
#include <cmath>
#include "binary_tree_node.h"
using namespace std;

class Pair {
public:
    int height;
    int diam;
};

Pair diameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair p;
        p.height = 0;
        p.diam = 0;
        return p;
    }
    Pair p;
    Pair p1, p2;
    p1 = diameter(root -> left);
    p2 = diameter(root -> right);
    p.height = 1+max(p1.height, p2.height);
    p.diam = max(p1.height+p2.height, max(p1.diam, p2.diam));
    return p;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    Pair p;
    p = diameter(root);
    cout << p.diam << endl;
}