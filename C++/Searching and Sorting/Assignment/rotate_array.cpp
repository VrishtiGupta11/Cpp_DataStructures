#include<iostream>
using namespace std;

// Approach 1
void RotateArray1(int arr[], int N, int rotatingPos){
    for(int i=0; i<rotatingPos; i++){
        int temp = arr[0], j=0;
        for(; j<N-1; j++){
            arr[j] = arr[j+1];
        }
        arr[j] = temp;
    }
}

// Approach 2
void RotateArray2(int arr[], int N, int rotatingPos){
    int newArr[100];
    for(int i=0; i<rotatingPos; i++){
        newArr[i] = arr[i];
    }
    int k = 0;
    for(int j=rotatingPos; j<N; j++){
        arr[k] = arr[j];
        k++;
    }
    int j = 0;
    for(int i=k; i<N; i++){
        arr[i] = newArr[j];
        j++;
    }
}

// Approach 3
void ReverseArray(int arr[], int start, int end){
    for(int i=start, j=end; i<j; i++, j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void RotateArray3(int arr[], int N, int rotatingPos){
    ReverseArray(arr, 0, N-1);
    ReverseArray(arr, 0, N-rotatingPos-1);
    ReverseArray(arr, N-rotatingPos, N-1);
}


int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N, array[100], D;
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>array[i];
        }
        cin>>D;
        // RotateArray1(array, N, D);
        // RotateArray2(array, N, D);
        RotateArray3(array, N, D);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
        testCases--;
    }
}