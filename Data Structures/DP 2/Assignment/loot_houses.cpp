#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Recursive
int lootHouses1(int idx, vector<int> &arr) {
    if(idx < 0) return 0;

    int pick = arr[idx] + lootHouses1(idx - 2, arr);
    int notPick = lootHouses1(idx - 1, arr);
 
    return max(pick, notPick);
}

// Memoization
int lootHouses2(int idx, vector<int> &arr, vector<int> &dp) {
    if(idx <= 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    int pick = arr[idx-1] + lootHouses2(idx - 2, arr, dp);
    int notPick = lootHouses2(idx - 1, arr, dp);
 
    return dp[idx] = max(pick, notPick);
}

// Tabulation
int lootHouses3(int N, vector<int> &arr) {
    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i=2; i<=N; i++) {
        int pick = arr[i-1] + dp[i - 2];
        int notPick = dp[i - 1];
    
        dp[i] = max(pick, notPick);
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    // Recursive
    cout << lootHouses1(N-1, arr) << endl;

    // Memoization
    vector<int> dp(N+1, -1);
    cout << lootHouses2(N, arr, dp) << endl;
    
    // Tabulation
    cout << lootHouses3(N, arr);
}