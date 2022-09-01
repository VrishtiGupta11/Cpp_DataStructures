#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Recursion
int lcs1(int i, int j, string str1, string str2) {
    if(i < 0 || j < 0) return 0;

    if(str1[i] == str2[j]) 
        return 1 + lcs1(i-1, j-1, str1, str2);
    else
        return max(lcs1(i-1, j, str1, str2), lcs1(i, j-1, str1, str2));
}

// Memization
int lcs2(int i, int j, string str1, string str2, vector<vector<int>> &dp) {
    if(i == 0 || j == 0) 
        return 0;
    
    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i-1] == str2[j-1])
        return dp[i][j] = 1+lcs2(i-1, j-1, str1, str2, dp);
    else
        return dp[i][j] = max(lcs2(i-1, j, str1, str2, dp), lcs2(i, j-1, str1, str2, dp));
}

// Tabulation
int lcs3(int n1, int n2, string str1, string str2) {
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}

int main() {
    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    // Recursion
    cout << lcs1(str1.length()-1, str2.length()-1, str1, str2) << endl;

    // Memoization
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    cout << lcs2(str1.size(), str2.size(), str1, str2, dp) << endl;

    // Tabulation
    cout << lcs3(str1.size(), str2.size(), str1, str2) << endl;
}