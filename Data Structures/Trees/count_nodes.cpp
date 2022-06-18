#include <iostream>
#include "tree_node.h"
using namespace std;

template <typename T>
int countNodes(TreeNode<T>* root) {
    int ans = 1;
    for(int i=0; i<root -> children.size(); i++) {
        ans += countNodes(root -> children[i]);
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    cout << countNodes(root);
}