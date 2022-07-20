#include <iostream>
#include "../Binary Trees/binary_tree_node.h"
using namespace std;

bool search(BinaryTreeNode<int>* root, int k) {
    bool ans = false;
    if(root == NULL)
        return false;
    if(root -> data == k)
        return true;
    else if(k > root -> data)
        ans = ans || search(root -> right, k);
    else 
        ans = ans || search(root -> left, k);
    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int k;
    cin >> k;
    bool isPresent = search(root, k);
    cout << (isPresent ? "True" : "False");
}