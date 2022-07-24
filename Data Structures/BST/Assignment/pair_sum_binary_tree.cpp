#include <iostream>
#include "../binary_tree_node.h"
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int low, int high, int mid)
{
    int i, j;
    vector<int> c;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c.push_back(arr[i]);
            i++;
        }
        else {
            c.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid) {
        c.push_back(arr[i]);
        i++;
    }
    while (j <= high) {
        c.push_back(arr[j]);
        j++;
    }
    for (i = low; i <= high; i++)  {
        arr.at(i) = c.at(i-low);
    }
}

void MergeSort(vector<int> &arr, int l, int h) {
    if(l >= h) 
        return;
    int mid = (h+l)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, l, h, mid);
}

void treeToArray(BinaryTreeNode<int>* root, vector<int> &arr) {
    if(root == NULL)
        return;
    arr.push_back(root -> data);
    treeToArray(root -> left, arr);
    treeToArray(root -> right, arr);
}

vector<int> pairSum(BinaryTreeNode<int>* root, int sum) {
    vector<int> arr;
    treeToArray(root, arr);
    MergeSort(arr, 0, arr.size()-1);
    int i=0, j=arr.size()-1;
    vector<int> pairs;
    while(i<j) {
        if(arr.at(i) + arr.at(j) == sum) {
            pairs.push_back(arr.at(i));
            pairs.push_back(arr.at(j));
            i++;
            j--;
        }
        else if(arr.at(i) + arr.at(j) < sum) {
            i++;
        }
        else {
            j--;
        }
    } 
    return pairs;    
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise<int>();
    int sum;
    cin >> sum;
    vector<int> pairs = pairSum(root, sum);
    for(int i=0; i<pairs.size(); i=i+2) {
        cout << pairs[i] << " " << pairs[i+1] << endl;
    }
    // int N;
    // cin >> N;
    // int input;
    // vector<int> arr;
    // for(int i=0; i<N; i++) {
    //     cin >> input;
    //     arr.push_back(input);
    // }
    // MergeSort(arr, 0, arr.size()-1);
    // for(int i=0; i<arr.size(); i++)
    //     cout << arr[i] << " ";

}