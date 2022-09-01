#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Memoization
int knapsack1(int i, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp) {
    // if(W == 0) return 0;
    if(i==0) {
        if(wt[0] == W) {
            return val[0];
        }
        else return 0;
    }
    
    if(dp[i][W] != -1) return dp[i][W];

    int pick = -1e9;
    if(wt[i] <= W) pick = val[i] + knapsack1(i-1, W-wt[i], wt, val, dp);
    int notPick = knapsack1(i-1, W, wt, val, dp);
    return dp[i][W] = max(pick, notPick);
}

// Tabulation
int knapsack2(int N, int W, vector<int> &wt, vector<int> &val) {
    vector<vector<int>> dp(N, vector<int>(W+1, 0));

    dp[0][wt[0]] = val[0];
    for(int i=1; i<N; i++) {
        for(int j=1; j<=W; j++) {
            int pick = -1e9;
            if(wt[i] <= j) pick = val[i] + dp[i-1][j-wt[i]];
            int notPick = dp[i-1][j];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[N-1][W];
}

int main() {
    int N, W;
    cin >> N;
    vector<int> wt(N);
    vector<int> val(N);
    for(int i=0; i<N; i++) 
        cin >> wt[i];
    for(int i=0; i<N; i++) 
        cin >> val[i];
    cin >> W;

    vector<vector<int>> dp(N, vector<int>(W+1, -1));
    cout << knapsack1(N-1, W, wt, val, dp) << endl;

    cout << knapsack2(N, W, wt, val) << endl;
}