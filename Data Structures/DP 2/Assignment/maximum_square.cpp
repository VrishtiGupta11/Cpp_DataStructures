#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxi = 0;
int f(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp) {
    if(i == 0 || j == 0) {
        if(matrix[i][j] == '1') return 0;
        else return 1;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(matrix[i][j] == '1') {
        f(i-1, j, matrix, dp);
        f(i, j-1, matrix, dp);
    }
    else {
        dp[i][j] = 1 + min(f(i-1, j-1, matrix, dp), min(f(i-1, j, matrix, dp), f(i, j-1, matrix, dp)));
        // cout << dp[i][j] << " ";
        maxi = max(maxi, dp[i][j]);
        return dp[i][j];
    }
    return dp[i][j] = 0;
}

int maximalSquare1(vector<vector<char>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();
    vector<vector<int>> dp(N, vector<int>(M, -1));
    f(N-1, M-1, matrix, dp);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return maxi;
}

// Tabulation
int maximalSquare(vector<vector<char>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();
    int maxi = INT_MIN;
    // vector<vector<int>> dp(N, vector<int>(M, -1));
    // f(N-1, M-1, matrix, dp);
    
    vector<vector<int>> dp(N, vector<int>(M, 0));
    for(int i=0; i<N; i++) {
        dp[i][0] = matrix[i][0] == '1' ? 0 : 1;
    }
    
    for(int j=0; j<M; j++) {
        dp[0][j] = matrix[0][j] == '1' ? 0 : 1;
    }
    
    for(int i=1; i<N; i++) {
        for(int j=1; j<M; j++) {
            if(matrix[i][j] == '1')
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            maxi = max(maxi, dp[i][j]);
        }
    }
    
    return maxi;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maximalSquare(matrix);
}