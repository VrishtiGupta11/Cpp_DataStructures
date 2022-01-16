#include<iostream>
using namespace std;

void WavePrint(int arr[][100], int M, int N){
    for(int i=0; i<N; i++){
        if(i%2==0)
            for(int j=0; j<M; j++)
                cout<<arr[j][i]<<" ";
        else
            for(int j=M-1; j>=0; j--)
                cout<<arr[j][i]<<" ";
    }
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0) {
        int arr[100][100], M, N;
        cin>>M>>N;

        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                cin>>arr[i][j];

        WavePrint(arr, M, N);

        cout<<endl;
        testCases--;
    }
}