#include <iostream>
#include "../tree_node.h"
using namespace std;

class Pair {
public:
    TreeNode<int>* largest;
    TreeNode<int>* slargest;
};

Pair helper(TreeNode<int>* root) {
    Pair ans;
    ans.largest = root;
    ans.slargest = NULL;

    for(int i=0; i<root -> children.size(); i++) {
        Pair temp = helper(root -> children[i]);
        if(temp.largest -> data > ans.largest -> data) {
            if((temp.slargest == NULL && ans.slargest == NULL) || temp.slargest == NULL) {
                ans.slargest = ans.largest;
                ans.largest = temp.largest;
            }
            else if((temp.slargest != NULL && ans.slargest != NULL) || ans.slargest == NULL) {
                ans.slargest = ans.largest -> data > temp.slargest -> data ? ans.largest : temp.slargest;
                ans.largest = temp.largest;
            }
        }
        else if(temp.largest -> data < ans.largest -> data) {
            if((temp.slargest == NULL && ans.slargest == NULL) || ans.slargest == NULL) 
                ans.slargest = temp.largest;
            else if((temp.slargest != NULL && ans.slargest != NULL) || temp.slargest == NULL)
                ans.slargest = temp.largest -> data > ans.slargest -> data ? temp.largest : ans.slargest;
        }
    }
    return ans;
}

TreeNode<int>* secondLargest(TreeNode<int>* root) {
    Pair p = helper(root);
    return p.slargest;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise<int>();
    TreeNode<int>* seclargest = secondLargest(root);
    cout << seclargest -> data;
}