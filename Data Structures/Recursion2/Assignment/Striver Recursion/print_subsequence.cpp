// Print subsequence or subset
#include <iostream>
#include <cmath>
using namespace std;

void printSubset(int arr[], int N, int output[], int m, int ind) {
    if(ind == N) {
        for(int i=0; i<m; i++) 
            cout << output[i] << " ";
        cout << endl;
        return;
    }
    output[m] = arr[ind];
    printSubset(arr, N, output, m+1, ind+1);
    printSubset(arr, N, output, m, ind+1);
}

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    int *output = new int[int(pow(2, N))];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    printSubset(arr, N, output, 0, 0);
}