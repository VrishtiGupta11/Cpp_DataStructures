#include<iostream>
using namespace std;

void SpiralPrint(int arr[][100], int M, int N){
    int rs = 0, re = M-1, cs = 0, ce = N-1, count = 0;
    while (count <= M*N)
    {
        for(int i=cs; i<=ce; i++){
            cout<<arr[rs][i]<<" ";
            rs++;
            count++;
        }
        for(int i=rs; i<=cs; i++){
            cout<<arr[i][ce]<<" ";
            ce--;
            count++;
        }
        for(int i=ce; i<=cs; i--){
            cout<<arr[re][i]<<" ";
            re--;
            count++;
        }
        for(int i=re; i<=rs; i--){
            cout<<arr[i][cs]<<" ";
            cs++;
            count++;
        }
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

        SpiralPrint(arr, M, N);

        cout<<endl;
        testCases--;
    }
}