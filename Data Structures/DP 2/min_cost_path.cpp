#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// Bruteforce
int minCost(int** arr, int M, int N, int i, int j) {
    if(i == M-1 && j == N-1)
        return arr[i][j];
    if(i >= M || j >= N) {
        return INT_MAX;
    }
    int down = minCost(arr, M, N, i+1, j);
    int right = minCost(arr, M, N, i, j+1);
    int diagonal = minCost(arr, M, N, i+1, j+1);
    return min(down, min(right, diagonal))  + arr[i][j];
}

// Memoization
int helper(int** arr, int M, int N, int i, int j, int** dp) {
    if(i == M-1 && j == N-1)
        return arr[i][j];
    if(i >= M || j >= N) {
        return INT_MAX;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    int down = helper(arr, M, N, i+1, j, dp);
    int right = helper(arr, M, N, i, j+1, dp);
    int diagonal = helper(arr, M, N, i+1, j+1, dp);
    return dp[i][j] = min(down, min(right, diagonal))  + arr[i][j];
}

int minCost2(int** arr, int M, int N, int i, int j) {
    int** dp = new int*[M];
    for(int i=0; i<M; i++) {
        dp[i] = new int[N];
        for(int j=0; j<N; j++) {
            dp[i][j] = -1;
        }
    }
    return helper(arr, M, N, i, j, dp);
}

// DP
int minCost3(int** arr, int M, int N) {
    int** dp = new int*[M];
    for(int i=0; i<M; i++) {
        dp[i] = new int[N];
    }
    dp[M-1][N-1] = arr[M-1][N-1];

    // Fill last row (right to left)
    for(int j=N-2; j >= 0; j--) {
        dp[M-1][j] = dp[M-1][j+1] + arr[M-1][j];
    }

    // Fill last column (bottom to top)
    for(int i=M-2; i >= 0; i--) {
        dp[i][N-1] = dp[i+1][N-1] + arr[i][N-1];
    }

    // fill remaining cells
    for(int i=M-2; i>=0; i--) {
        for(int j=N-2; j>=0; j--) { 
            dp[i][j] = min(dp[i][j+1], min(dp[i+1][j+1], dp[i+1][j])) + arr[i][j];
        }

    }
    return dp[0][0];
}

int main() {
    int M, N;
    cin >> M >> N;
    int** arr = new int*[M];
    for(int i=0; i<M; i++) {
        arr[i] = new int[N];
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    // Bruteforce
    cout << minCost(arr, M, N, 0, 0) << endl;

    // Memoization
    cout << minCost2(arr, M, N, 0, 0) << endl;

    // DP
    cout << minCost3(arr, M, N) << endl;
}