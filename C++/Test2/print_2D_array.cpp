#include<iostream>
using namespace std;

void Print2DArray(int arr[][100], int N, int M){
    for(int j=0; j<N; j++){
        for(int i = N-j-1; i>=0; i--){
            for(int k=0; k<M; k++){
                cout<<arr[j][k]<<" ";           
            }
            cout<<endl;
        }
    }
}

int main() {
    int N, M, arr[100][100];
    cin>>N>>M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>arr[i][j];
    Print2DArray(arr, N, M);
}