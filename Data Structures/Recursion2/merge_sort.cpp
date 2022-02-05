#include <iostream>
using namespace std;

void Merge(int arr1[], int N1, int N2) {
    int arr[1000], i=0, j=N1, k=0;
    while (i < N1 && j < N2) {
        if(arr1[i] < arr1[j])
            arr[k++] = arr1[i++];
        else
            arr[k++] = arr1[j++];
    }
    while (i < N1) {
        arr[k++] = arr1[i++];
    }
    while (j < N2) {
        arr[k++] = arr1[j++];
    }
    for(int i=0; i<k; i++)
        arr1[i] = arr[i];
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h) 
        return;
    int mid = (l+h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, mid-l+1, h+1);
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