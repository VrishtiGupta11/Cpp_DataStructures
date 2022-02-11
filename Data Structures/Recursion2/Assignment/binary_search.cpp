#include <iostream>
using namespace std;

int BinarySearch(int arr[], int l, int h, int X) {
    if(l > h) 
        return -1;
    int mid = (l+h)/2;
    if(X == arr[mid])
        return mid+1;
    else if(X < arr[mid])
        BinarySearch(arr, l, mid-1, X);
    else
        BinarySearch(arr, mid+1, h, X);
}

int main() {
    int N, arr[100], X;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> X;
    cout << BinarySearch(arr, 0, N-1, X);
}