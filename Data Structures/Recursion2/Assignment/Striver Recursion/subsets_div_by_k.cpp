#include <iostream>
#include <cmath>
using namespace std;

void printSubsets(int arr[], int N, int ind, int output[], int m, int sum, int k) {
    if(ind == N) {
        if(sum%k == 0) {
            for(int i=0; i<m; i++)
                cout << output[i] << " ";
            cout << endl;
        }
        return;
    }
    output[m] = arr[ind];
    printSubsets(arr, N, ind+1, output, m+1, sum+arr[ind], k);
    printSubsets(arr, N, ind+1, output, m, sum, k);
}

int main() {
    int N, k;
    cin >> N;
    int *arr = new int[N];
    int *output = new int[int(pow(2, N))];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cin >> k;
    printSubsets(arr, N, 0, output, 0, 0, k);
} 