#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this -> data = data;
    }

    ~TreeNode() {
        for(int i=0; i<children.size(); i++) {
            delete children[i];
        }
    }
};

// Depth wise printing
template <typename T>
void printTree(TreeNode<T>* root) {
    if(root == NULL)
        return;
    cout << root -> data << ":";
    for(int i=0; i<root -> children.size(); i++) {
        cout << root -> children[i] -> data << " ";
    }
    cout << endl;

    for(int i=0; i<root -> children.size(); i++) {
        printTree(root -> children[i]);
    }
}

// Depth wise taking Input
template <typename T>
TreeNode<T>* takeInput() {
    int rootData;
    cout << "Enter Node Data: ";
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    
    int n;
    cout << "Enter number of children of " << rootData <<": ";
    cin >> n;
    for(int i=0; i<n; i++) {
        TreeNode<T>* child = takeInput<T>();
        root -> children.push_back(child);
    }
    return root;
}

// Level wise input
template <typename T>
TreeNode<T>* takeInputLevelWise() {
    T rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    TreeNode<T>* root = new TreeNode<T>(rootData);
    queue<TreeNode<T>*> q;
    q.push(root);
    while(q.size() != 0) {
        TreeNode<T>* front = q.front();
        q.pop();
        cout << "Enter number of children of " << front -> data << ": ";
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            T nodeData;
            cout << "Enter " << i << "th children of " << front -> data << ": ";
            cin >> nodeData;
            TreeNode<T>* child = new TreeNode<T>(nodeData);
            front -> children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

// Level wise printing
template <typename T>
void printTreeLevelWise(TreeNode<T>* root) {
    queue<TreeNode<T>*> q;
    q.push(root);
    while(q.size() != 0) {
        TreeNode<T>* front = q.front();
        q.pop();
        cout << front -> data << ": ";
        for(int i=0; i<front -> children.size(); i++) {
            cout << front -> children[i] -> data << " ";
            q.push(front -> children[i]);
        }
        cout << endl;
    }
}