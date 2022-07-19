#include <iostream>
#include <stack>
#include <queue>
#include "../binary_tree_node.h"
using namespace std;

void zigzag(BinaryTreeNode<int>* root) {
    stack<BinaryTreeNode<int>*> st1;
    stack<BinaryTreeNode<int>*> st2;
    st1.push(root);
    while(st1.size() != 0 || st2.size() != 0) {
        while(st1.size() != 0) {
            BinaryTreeNode<int>* front = st1.top();
            st1.pop();
            cout << front -> data << " ";
            if(front -> left != NULL)
                st2.push(front -> left);
            if(front -> right != NULL)
                st2.push(front -> right);
        }
        cout << endl;
        while(st2.size() != 0) {
            BinaryTreeNode<int>* front = st2.top();
            st2.pop();
            cout << front -> data << " ";
            if(front -> right != NULL)
                st1.push(front -> right);
            if(front -> left != NULL)
                st1.push(front -> left);
        }
        cout << endl;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    zigzag(root);
}