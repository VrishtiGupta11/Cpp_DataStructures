#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int coinTower(int i, int X, int Y, vector<int> &dp) {
    if(i == 1 || i == X || i == Y) return 1;
    if(dp[i] != -1) return dp[i];

    int ans1 = 0, ans2 = 0, ans3 = 0;
    if(i > 1) ans1 = coinTower(i-1, X, Y, dp) ^ 1;
    if(i > X) ans2 = coinTower(i-X, X, Y, dp) ^ 1;
    if(i > Y) ans3 = coinTower(i-Y, X, Y, dp) ^ 1;
    return dp[i] = max(ans1, max(ans2, ans3));
}

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> dp(N+1, -1);
    cout << (coinTower(N, X, Y, dp) == 1 ? "Beerus" : "Whis");
}