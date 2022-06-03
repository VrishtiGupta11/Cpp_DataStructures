#include <iostream>
using namespace std;
/*
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
*/

void printSubset(int arr[], int N, int ind, int m, int output[]) {
    if(ind == N) {
        for(int i=0; i<m; i++) 
            cout << output[i];
        cout << endl;
        return;
    }
    output[m] = arr[ind];
    printSubset(arr, N, ind+1, m+1, output);
    printSubset(arr, N, ind+1, m, output);
}

int main() {
    int N, arr[100], output[100];
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    printSubset(arr, N, 0, 0, output);

    return 0;
}