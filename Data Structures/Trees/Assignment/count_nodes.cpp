#include <iostream>
#include "../tree_node.h"
using namespace std;

int countNodes(TreeNode<int>* root, int x) {
    int count = 0;
    for(int i=0; i<root -> children.size(); i++) 
        count += countNodes(root -> children[i], x);
    if(root -> data > x) 
        return 1+count;
    return count;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << countNodes(root, x);
}