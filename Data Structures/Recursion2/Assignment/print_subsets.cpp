#include <iostream>
using namespace std;

void PrintSubset(int arr[], int N, int output[], int M) {
    if(N == 0) {
        for(int i=0; i < M; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }
    PrintSubset(arr+1, N-1, output, M);
    output[M] = arr[0];
    PrintSubset(arr+1, N-1, output, M+1);
}

int main() {
    int N, arr[100], output[100];
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    PrintSubset(arr, N, output, 0);
}