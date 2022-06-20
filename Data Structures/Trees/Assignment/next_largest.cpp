#include <iostream>
#include "../tree_node.h"
using namespace std;

TreeNode<int>* nextLargest(TreeNode<int>* root, int x) {
    TreeNode<int>* nextLarg = NULL;
    if(root -> data > x)
        nextLarg = root;
    for(int i=0; i<root -> children.size(); i++) {
        TreeNode<int>* temp = nextLargest(root -> children[i], x);
        if(temp != NULL && (nextLarg == NULL || temp -> data < nextLarg -> data)) 
            nextLarg = temp;
    }
    return nextLarg;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    int x;
    cout << "Enter x: ";
    cin >> x;
    TreeNode<int>* nextLarg = nextLargest(root, x);
    cout << nextLarg -> data;
}