#include <iostream>
using namespace std;

// Bruteforce
int staircase1(int N) {
    if(N == 0)
        return 1;
    else if(N < 0) 
        return 0;
    return staircase1(N-1) + staircase1(N-2) + staircase1(N-3);
}

// Memoization
int helper2(int N, int* arr) {
    if(N == 0)
        return 1;
    else if(N < 0)
        return 0;
    if(arr[N] != -1)
        return arr[N];
    arr[N] = helper2(N-1, arr) + helper2(N-2, arr) + helper2(N-3, arr);
    return arr[N];
}

int staircase2(int N) {
    int* arr = new int[N+1];
    for(int i=0; i<=N; i++) 
        arr[i] = -1;
    return helper2(N, arr);
}

// DP
int staircase3(int N) {
    int* dp = new int[N+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;
    // Bruteforce
    cout << staircase1(N) << endl;

    // Memoization
    cout << staircase2(N) << endl;

    // DP
    cout << staircase3(N) << endl;
}