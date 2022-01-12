#include<iostream>
using namespace std;

void ZeroToEnd(int arr[], int N){
    int i=0, j=0;
    while (i < N && j < N)
    {
        if(arr[i] == 0 && arr[j] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
        if(arr[i] != 0 && i<N){
            i++;
            j++;
        }
        if(arr[j] == 0 && j<N){
            j++;
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
        ZeroToEnd(array, N);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
        testCases--;
    }
}