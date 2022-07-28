#include <iostream>
using namespace std;

void Merge(int arr1[], int l, int h, int mid) {
    int arr[1000], i=l, j=mid+1, k=0;
    while (i <= mid && j <= h) {
        if(arr1[i] < arr1[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr1[j++];
    }
    while (i <= mid) {
        arr[k++] = arr1[i++];
    }
    while (j <= h) {
        arr[k++] = arr1[j++];
    }
    for(int i=l; i<=h; i++)
        arr1[i] = arr[i-l];
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h) 
        return;
    int mid = (l+h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, l, h, mid);
}

int main() {
    int arr[100], N;
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    MergeSort(arr, 0, N-1);
    for(int i=0; i<N; i++)
        cout << arr[i] << " ";
}