#include<iostream>
using namespace std;

// Approach1
void sort01(int arr[], int N){
    int count = 0;
    for(int i=0; i<N; i++){
        if(arr[i] == 1){
            count++;
            arr[i] = 0;
        }
    }
    for(int i=1; i<=count; i++){
        arr[N-i] = 1;
    }
}

// Approach2
void SORT01(int arr[], int N){
    int i=0, j=N-1;
    while (i<j)
    {
        if(arr[i] == 1 && arr[j] == 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        if(arr[i]==0){
            i++;
        }
        if(arr[j]==1){
            j--;
        }
    }
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0)
    {
        int N, array[100];
        cin>>N;
        for(int i=0; i<N; i++){
            cin>>array[i];
        }
        SORT01(array, N);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }

        cout<<endl;
        testCases--;
    }
}