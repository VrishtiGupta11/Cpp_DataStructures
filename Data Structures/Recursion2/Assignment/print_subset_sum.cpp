#include <iostream>
using namespace std;

void PrintSubsetSum(int arr[], int size, int k, int output[], int m) {
    if(size == 0) {
        if(k == 0) {
            for(int i=0; i<m; i++)
                cout << output[i] << " ";
            cout << endl;
            return;
        }
        else {
            return;
        }
    }

    output[m] = arr[0];
    PrintSubsetSum(arr + 1, size - 1, k - arr[0], output, m+1);
    PrintSubsetSum(arr + 1, size - 1, k, output, m);
    
}

int main() {
    int N, k, arr[100], output[100];
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> k;
    PrintSubsetSum(arr, N, k, output, 0);
}