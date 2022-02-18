#include <iostream>
using namespace std;

// Approach 1: O(n^2)

// Approach 2: mlogm + nlogn + m + n --> O(nlogn)
// Sort both the arrays and then find intersection
void Merge(int arr[], int l, int mid, int h) {
    int arr1[100], i = l, j = mid+1, k=0;
    while(i <= mid && j <= h) {
        if(arr[i] < arr[j])
            arr1[k++] = arr[i++];
        else 
            arr1[k++] = arr[j++];
    }
    while(i <= mid) {
        arr1[k++] = arr[i++];
    }
    while(j <= h) {
        arr1[k++] = arr[j++];
    }
    for(int i=l; i <= h; i++) {
        arr[i] = arr1[i-l];
    }
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h)
        return;
    int mid = (l + h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, l, mid, h);
}

int FindIntersection(int arr1[], int N1, int arr2[], int N2, int output[]) {
    int i=0, j=0, k=0;
    MergeSort(arr1, 0, N1-1);
    MergeSort(arr2, 0, N2-1);

    while(i < N1 && j < N2) {
        if(arr1[i] == arr2[j]) {
            output[k++] = arr1[i++];
            j++;
        }
        else if(arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    return k;
}

int main() {
    int testCases, testCasesCopy, outputSize;
    cin >> testCases;
    testCasesCopy = testCases;
    // int** output = new int*[testCasesCopy];

    while (testCases > 0) {
        int N1, N2, output[100];
        cin >> N1;
        int* arr1 = new int[N1];
        for(int i=0; i<N1; i++) 
            cin>>arr1[i];

        cin >> N2;
        int* arr2 = new int[N2];
        for(int i=0; i<N2; i++) 
            cin>>arr2[i];

        outputSize = FindIntersection(arr1, N1, arr2, N2, output);

        for(int i=0; i<outputSize; i++) {
            cout << output[i] << " ";
        }
        
        cout<<endl;
        testCases--;
    }
    
}