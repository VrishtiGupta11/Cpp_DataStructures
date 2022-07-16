#include <iostream>
#include <climits>
#include "binary_tree_node.h"
using namespace std;

class Pair {
public:
    int min;
    int max;
};

Pair maxMin(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        Pair pair;
        pair.max = INT_MIN;
        pair.min = INT_MAX;
        return pair;
    }

    Pair leftP = maxMin(root -> left);
    Pair rightP = maxMin(root -> right);
    Pair p;
    
    p.max = (leftP.max > rightP.max) ? ((root -> data > leftP.max) ? root -> data : leftP.max) : ((root -> data > rightP.max) ? root -> data : rightP.max);
    p.min = (leftP.min < rightP.min) ? ((root -> data < leftP.min) ? root -> data : leftP.min) : ((root -> data < rightP.min) ? root -> data : rightP.min);
    return p;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    Pair ans = maxMin(root);
    cout << "Max: " << ans.max << endl;
    cout << "Min: " << ans.min << endl;
}