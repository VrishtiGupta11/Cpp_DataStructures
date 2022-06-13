#include <iostream>
#include <cmath>
using namespace std;

// Print subsets whose sum == s where repetition of elements is allowed.
void printSubsets(int arr[], int N, int ind, int output[], int m, int sum) {
    if(ind == N) {
        if(sum == 0) {
            for(int i=0; i<m; i++) 
                cout << output[i] << " ";
            cout << endl;
        }
        return;
    }
    if(arr[ind] <= sum) {
        output[m] = arr[ind];
        printSubsets(arr, N, ind, output, m+1, sum-arr[ind]);
    }
    printSubsets(arr, N, ind+1, output, m, sum);
}

int main() {
    int N, sum;
    cin >> N;
    int *arr = new int[N];
    int *output = new int[int(pow(2, N))];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cin >> sum;
    printSubsets(arr, N, 0, output, 0, sum);
}