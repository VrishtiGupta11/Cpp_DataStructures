#include<iostream>
using namespace std;

bool Search(int arr[], int N, int X) {
    if (N <= 0)
        return false;
    int mid = (N - 1)/2;
    if (arr[mid] == X)
        return true;
    else if (X > arr[mid])
        return Search(arr + mid + 1, N - mid - 1, X);
    else 
        return Search(arr, mid, X);
}

int main() {
    int N, X;
    cin >> N;
    int* arr = new int[N];
    // Input => Sorted Array
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> X;
    if(Search(arr, N, X))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}