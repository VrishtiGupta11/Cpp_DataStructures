#include <iostream>
#include <vector>
using namespace std;

long long int f(int idx, int target, vector<int> arr, vector<vector<long long int>> &dp) {
    if(target == 0) return 1; 
    if(idx == 0) {
        if(target % arr[0] == 0) return 1;
        else return 0;
    }
    
    if(dp[idx][target] != -1) return dp[idx][target];

    long long int pick = 0;
    if(arr[idx] <= target)
        pick = f(idx, target-arr[idx], arr, dp);
    long long int notPick = f(idx-1, target, arr, dp);
    return dp[idx][target] = pick + notPick;
}

long long int waysToMakeCoinChange(int N, int target, vector<int> &arr) {
    vector<vector<long long int>> dp(N, vector<long long int>(target+1, -1));
    return f(N-1, target, arr, dp);
}

int main() {
    int N, target;
    vector<int> arr(N);
    cin >> N;
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cin >> target;
    cout << waysToMakeCoinChange(N, target, arr);
}