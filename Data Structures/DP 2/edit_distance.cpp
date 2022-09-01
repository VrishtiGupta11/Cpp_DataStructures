#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int editDistance1(int i, int j, string str1, string str2, vector<vector<int>> &dp) {
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i-1] == str2[j-1]) 
        return dp[i][j] = editDistance1(i-1, j-1, str1, str2, dp);
    else
        return dp[i][j] = 1 + min(editDistance1(i-1, j-1, str1, str2, dp), min(editDistance1(i-1, j, str1, str2, dp), editDistance1(i, j-1, str1, str2, dp)));
}

int editDistance2(int n1, int n2, string str1, string str2) {
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    for(int i=0; i<=n1; i++) 
        dp[i][0] = i;

    for(int j=0; j<=n2; j++) 
        dp[0][j] = j;

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(str1[i-1] == str2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }
    return dp[n1][n2];
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;

    // Memoization
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    cout << editDistance1(str1.size(), str2.size(), str1, str2, dp) << endl;

    // Tabulation
    cout << editDistance2(str1.size(), str2.size(), str1, str2) << endl;
}