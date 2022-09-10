#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int f(int i, int j, string S, string V, vector<vector<int>> dp) {
    // if i exceeds size than return some very big or some very small value
    if(i >= S.size()) return 1000;
    if(j >= S.size()) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int k = j;
    for(; k<V.size(); k++) {
        if(S[i] == V[k]) break;
    }

    // If not match then we will consider that element
    if(k == V.size()) return 1;

    // If match then we have choice of picking or not picking
    int pick = 1 + f(i+1, k+1, S, V, dp);
    int notPick = f(i+1, j, S, V, dp);

    return dp[i][j] = min(pick, notPick);
}

int scs(string S, string V, int N, int M) { 
    vector<vector<int>> dp(N, vector<int>(M, -1));
    return f(0, 0, S, V, dp);
}

int main() {
    string S, V;
    cin >> S >> V;
    int N = S.size(), M = V.size();
    cout << scs(S, V, N, M) << endl;
}