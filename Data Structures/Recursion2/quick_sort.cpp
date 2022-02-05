#include <iostream>
using namespace std;

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partitioning(int arr[], int si, int ei) {
    int count = 0;
    for(int i=si+1; i <= ei; i++) {
        if(arr[i] < arr[si]) 
            count++;
    }
    
    Swap(arr+si+count, arr+si);

    int i = si, j=ei;
    while(i < j) {
        if(arr[i] < arr[si+count]) 
            i++;
        if(arr[j] > arr[si+count])
            j--;
        else {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // while(i < j) {
    //     if(arr[i] > arr[si+count]) {
    //         if(arr[j] < arr[si+count]) {
    //             Swap(arr+i, arr+j);
    //             i++;
    //             j--;
    //         }
    //         else
    //             j--;
    //     }
    //     else
    //         i++;
    // }
    return si+count;
}

void QuickSort(int arr[], int si, int ei) {
    if(si >= ei)
        return;
    int pivot = Partitioning(arr, si, ei);
    QuickSort(arr, si, pivot-1);
    QuickSort(arr, pivot+1, ei);
}

int main() {
    int N, arr[100];
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    QuickSort(arr, 0, N-1);
    for(int i=0; i<N; i++) 
        cout << arr[i] << " ";
}