#include<iostream>
using namespace std;

void MergeSortedArrays(int arr[], int arr1[], int N1, int arr2[], int N2){
    int i=0, j=0, k=0;
    while (i<N1 && j<N2) {
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while (i < N1) {
        arr[k++] = arr1[i++];
    }
    while (j < N2) {
        arr[k++] = arr2[j++];
    }
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N1, N2, arr1[100], arr2[100], arr[100];
        cin>>N1;
        for(int i=0; i<N1; i++){
            cin>>arr1[i];
        }
        cin>>N2;
        for(int i=0; i<N2; i++){
            cin>>arr2[i];
        }
        MergeSortedArrays(arr, arr1, N1, arr2, N2);
        for(int i=0; i<N1+N2; i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl;
        testCases--;
    }
}