#include <iostream>
#include <queue>
#include "../binary_tree_node.h"
using namespace std;

void levelOrderTraversal(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(q.size() != 0) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front != NULL) {
            cout << front -> data << " ";
            if(front -> left != NULL) 
                q.push(front -> left);
            if(front -> right != NULL) 
                q.push(front -> right);
        }
        else {
            if(q.size() != 0) {
                cout << endl;
                q.push(NULL);
            }
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    levelOrderTraversal(root);
}