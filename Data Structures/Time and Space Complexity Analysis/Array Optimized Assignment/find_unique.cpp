#include <iostream>
using namespace std;

// Approach 1
// O(n^2)

// Approach 2 : Sort and scan
// O(nlogn)
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
    for(int i=0; i<N2; i++)
        arr1[i] = arr[i];
}

void MergeSort(int arr[], int l, int h) {
    if(l >= h) 
        return;
    int mid = (l+h)/2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, h);
    Merge(arr, mid+1, h+1);
}

int FindUnique1(int arr[], int N) {
    MergeSort(arr, 0, N);
    int elem;
    for(int i=0; i<N; i++)
        cout << arr[i] << " ";
    cout << endl;
    for(int i=0; i<N; i++) {
        if(arr[i] != arr[i+1]) {
            if(i == 0) {
                elem = arr[i];
                break;
            }
            if(arr[i-1] != arr[i]) {
                elem = arr[i];
                break;
            }
        }
    }
    return elem;
}

// Approach 3 : X-or of two same numbers is 0 and X-or of 0 with number is number itself.
// O(n)
int FindUnique2(int arr[], int N) {
    int number = 0;
    for(int i=0; i<N; i++)
        number = number^arr[i];
    return number;
}

int main() {
    int testCases, testCasesCopy, output[100];
    cin>>testCases;
    testCasesCopy = testCases;
    while (testCases > 0)
    {
        int N, array[100];
        cin>>N;
        for(int i=0; i<N; i++) {
            cin>>array[i];
        }
        // output[testCasesCopy-testCases] = FindUnique1(array, N);
        output[testCasesCopy-testCases] = FindUnique2(array, N);

        cout<<endl;
        testCases--;
    }
    for(int i=0; i<testCasesCopy; i++) {
        cout<<output[i]<<endl;
    }
}