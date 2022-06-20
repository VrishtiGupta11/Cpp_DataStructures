#include <iostream>
#include "../tree_node.h"
using namespace std;

void replaceWithDepth(TreeNode<int>* root, int k) {
    if(root == NULL) 
        return;
    root -> data = k;
    for(int i=0; i<root -> children.size(); i++) 
        replaceWithDepth(root -> children[i], k+1);
}

void printLevelATNewLine(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        TreeNode<int>* first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        for (int i = 0; i < first->children.size(); i++) {
            q.push(first->children[i]);
        }
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    replaceWithDepth(root, 0);
    printLevelATNewLine(root);
}