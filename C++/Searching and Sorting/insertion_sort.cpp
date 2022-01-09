#include<iostream>
using namespace std;

void InsertionSort(int arr[], int N){
    for(int i=1; i<N; i++){
        int temp = arr[i], j;
        for(j=i-1; j>=0; j--){
            if(temp < arr[j]){
                arr[j+1] = arr[j];
            }
            else if(arr[i] > arr[j]){
                break;
            }
        }
        arr[j+1] = temp;
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
        InsertionSort(array, N);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }

        cout<<endl;
        testCases--;
    }
}