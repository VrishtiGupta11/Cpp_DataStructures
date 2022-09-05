#include <iostream>
#include <vector>
using namespace std;

// Minimum operations required to multiply N matrices.
// Here i points to starting matrix and j points to ending matrix
int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k=i; k<j; k++) {
        int step = arr[i-1]*arr[k]*arr[j] + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, step);
    }
    return dp[i][j] = mini;
}

int matrixChainMultiplication(int N, vector<int> &arr) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N-1, arr, dp);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cout << matrixChainMultiplication(N, arr);
}