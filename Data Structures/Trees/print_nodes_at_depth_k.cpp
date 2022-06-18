#include <iostream>
#include "tree_node.h"
using namespace std;

void printNodesAtDekthK(TreeNode<int>* root, int k) {
    if(root == NULL) // Edge Case
        return;
    if(k == 0) {
        cout << root -> data << endl;
        return;
    }
    for(int i=0; i<root -> children.size(); i++)
        printNodesAtDekthK(root -> children[i], k-1);
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    int k;
    cout << "Enter Depth: ";
    cin >> k;
    printNodesAtDekthK(root, k);
}