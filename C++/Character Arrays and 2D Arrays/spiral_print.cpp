#include<iostream>
using namespace std;

void SpiralPrint(int arr[][50], int M, int N) {
    int rs = 0, re = M-1, cs = 0, ce = N-1, count = 0;
    while (count < M*N)
    {
        for(int i=cs; i<=ce; i++){
            cout<<arr[rs][i]<<" ";
            count++;
        }
        rs++;
        if(count < M*N) {
            for(int i=rs; i<=re; i++){
                cout<<arr[i][ce]<<" "; 
                count++;
            }
            ce--;
        }
        if(count < M*N) {
            for(int i=ce; i>=cs; i--){
                cout<<arr[re][i]<<" ";
                count++;
            }
            re--;
        }
        if(count < M*N) {
            for(int i=re; i>=rs; i--){
                cout<<arr[i][cs]<<" ";
                count++;
            }
            cs++;
        }
    }
    
}

int main() {
    int testCases;
    cin>>testCases;
    while (testCases > 0) {
        int arr[50][50], M, N;
        cin>>M>>N;

        for(int i=0; i<M; i++)
            for(int j=0; j<N; j++)
                cin>>arr[i][j];

        SpiralPrint(arr, M, N);

        cout<<endl;
        testCases--;
    }
}