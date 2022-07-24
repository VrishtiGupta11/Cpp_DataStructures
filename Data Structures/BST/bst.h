#include "../Binary Trees/binary_tree_node.h"
#include <queue>
#include <iostream>
using namespace std;

class BST {
private:
    BinaryTreeNode<int>* root;

    bool hasData(int data, BinaryTreeNode<int>* root) {
        if(root == NULL) {
            return false;
        }
        bool ans = false;
        if(data == root -> data)
            return true;
        else if(data > root -> data)
            ans = ans || hasData(data, root -> right);
        else
            ans = ans || hasData(data, root -> left);
        return ans;
    } 

    BinaryTreeNode<int>* insertData(BinaryTreeNode<int>* root, int data) {
        if(root == NULL) {
            root = new BinaryTreeNode<int>(data);
            return root;
        }
        BinaryTreeNode<int>* node;
        if(data >= root -> data) {
            node = insertData(root -> right, data);
            root -> right = node;
        }
        else {
            node = insertData(root -> left, data);
            root -> left = node;
        }
        return root;
    }

    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* root, int data) {
        if(root == NULL)
            return NULL;
        if(data < root -> data) {
            root -> left = deleteData(root -> left, data);
            return root;
        }
        else if(data > root -> data) {
            root -> right = deleteData(root -> right, data);
            return root;
        }
        else {
            if(root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }
            else if(root -> left == NULL) {
                BinaryTreeNode<int>* temp = root -> right;
                root -> right = NULL;
                delete root;
                return temp;
            }
            else if(root -> right == NULL) {
                BinaryTreeNode<int>* temp = root -> left;
                root -> right = NULL;
                delete root;
                return temp;
            }
            else {
                BinaryTreeNode<int>* minNode = root -> right;
                while(minNode->left != NULL) {
                    minNode = minNode -> left;
                }
                int rightMin = minNode -> data;
                root -> data = rightMin;
                root -> right = deleteData(root -> right, rightMin);
                return root;
            }
        }
    }

    void printTreeLevelWise(BinaryTreeNode<int>* root) {
    if(root == NULL) 
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.size() != 0) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout << front -> data << ": ";
        if(front -> left != NULL) {
            cout << "L" << front -> left -> data << " ";
            q.push(front -> left);
        }
        if(front -> right != NULL) {
            cout << "R" << front -> right -> data;
            q.push(front -> right);
        }
        cout << endl;
    }
}

public:
    BST() {
        root = NULL;
    }

    void insertData(int data) {
        this -> root = insertData(this -> root, data);
    }

    void deleteData(int data) {
        this -> root = deleteData(this -> root, data);
    }

    bool hasData(int data) {
        return hasData(data, this -> root);
    }
    void printTree() {
        printTreeLevelWise(this -> root);
    }
};