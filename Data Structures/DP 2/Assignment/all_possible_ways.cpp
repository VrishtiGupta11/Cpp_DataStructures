#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int f(int idx, int sum, int power, vector<int> &arr, vector<vector<int>> &dp) {   
    int res = pow(arr[idx], power);

    if(sum == 0) return 1;
    if(idx == 0) {
        if(res == sum) return 1;
        else return 0;
    }
    
    if(dp[idx][sum] != -1) return dp[idx][sum];

    int pick = 0;
    if(res <= sum) 
        pick = f(idx-1, sum-res, power, arr, dp);
    int notPick = f(idx - 1, sum, power, arr, dp);
    return dp[idx][sum] = (pick + notPick) % 1000000007;
}

// int f(int sum, int power, int base) {   
//     int res = pow(base, power);

//     if(res == sum) return 1;
//     if(res > sum) return 0;

//     int pick = 0;
//     if(res <= sum) 
//         pick = f(sum-res, power, base + 1);
//     int notPick = f(sum, power, base + 1);
//     return pick + notPick;
// }

int allPossibleWays(int sum, int power) {
    int N = pow(sum, (float)1/power);
    vector<int> arr(N);

    for(int i=1; i<=N; i++) {
        arr[i-1] = i;
    }

    vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
    
    if(arr.size() == 0) return 0;
    else return f(N-1, sum, power, arr, dp);
    // return f(sum, power, 1);
}

int main() {
    int sum, power;
    cin >> sum >> power;
    cout << allPossibleWays(sum, power);
}