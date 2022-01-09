#include<iostream>
using namespace std;

void BubbleSort(int arr[], int N){
    int start = 0;
    while (start < N-1) {
        for(int i=1; i<N; i++) {
            if(arr[i-1] > arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
            }
        }
        N--;
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
        BubbleSort(array, N);
        for(int i=0; i<N; i++){
            cout<<array[i]<<" ";
        }

        cout<<endl;
        testCases--;
    }
}