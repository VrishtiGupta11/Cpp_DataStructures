#include <iostream>
#include "../tree_node.h"
using namespace std;

// Approach 1
TreeNode<int>* maxChildNode1(TreeNode<int>* root) {
    TreeNode<int>* max = root;
    int sum = root -> data;
    for(int i=0; i<root -> children.size(); i++) 
        sum += root -> children[i] -> data;

    for(int i=0; i<root -> children.size(); i++) {
        TreeNode<int>* tempNode = maxChildNode1(root -> children[i]);
        int tempSum = tempNode -> data;
        for(int i=0; i<tempNode -> children.size(); i++) 
            tempSum += tempNode -> children[i] -> data;
        if(tempSum > sum)
            max = tempNode;
    } 
    return max;
}

// Approach 2
class Pair {
public:
    TreeNode<int>* node;
    int sum;
};

Pair maxChildNode2(TreeNode<int>* root) {
    Pair max;
    max.node = root;
    max.sum = root -> data;
    for(int i=0; i<root -> children.size(); i++) 
        max.sum += root -> children[i] -> data;
    for(int i=0; i<root -> children.size(); i++) {
        Pair temp;
        temp = maxChildNode2(root -> children[i]);
        if(temp.sum > max.sum) 
            max = temp;
    }
    return max;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    // TreeNode<int>* maxNode = maxChildNode1(root);
    Pair max = maxChildNode2(root);
    cout << max.node -> data;
}