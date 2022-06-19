#include <iostream>
#include "../tree_node.h"
using namespace std;

bool containsX(TreeNode<int>* root, int x) {
    bool ans = false;
    if(root == NULL)
        return false;
    if(root -> data == x) 
        return true;
    for(int i=0; i<root -> children.size(); i++) 
        ans = ans || containsX(root -> children[i], x);
    return ans;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << (containsX(root, x) ? "True" : "False");
}