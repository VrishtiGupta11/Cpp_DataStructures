#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// Minimum steps to 1

// Approach 1 -> Recursion (Brute Force)
int minSteps1(int N) {
    if(N<=1) {
        return 0;
    }
    int x = minSteps1(N-1);
    int y = INT_MAX, z = INT_MAX;
    if(N%3 == 0) {
        y = minSteps1(N/3);
    }
    if(N%2 == 0) {
        y = minSteps1(N/2);
    }
    return 1 + min(x, min(y, z));
}

// Approach 2 -> Memoization
int helper2(int N, int* arr) {
    if(N<=1) {
        return 0;
    }
    // check if output already exists
    if(arr[N] != -1) {
        return arr[N];
    }

    int x = helper2(N-1, arr);
    int y = INT_MAX, z = INT_MAX;
    if(N%3 == 0) {
        y = helper2(N/3, arr);
    }
    if(N%2 == 0) {
        y = helper2(N/2, arr);
    }
    arr[N] = 1 + min(x, min(y, z));
    return arr[N];
}

int minSteps2(int N) {
    int* arr = new int[N+1];
    for(int i=0; i<=N; i++) {
        arr[i] = -1;
    }
    return helper2(N, arr);
}

// Approach 3 -> DP
int minSteps3(int N) {
    int* arr = new int[N+1];
    int x, y = INT_MAX, z = INT_MAX;
    arr[1] = 0;
    for(int i=2; i<=N; i++) {
        x = i-1;
        if(i%2 == 0)
            y = i/2;
        if(i%3 == 0)
            z = i/3;
        arr[i] = min(z, min(y, z));
    }
    return arr[N];
}

int main() {
    int N;
    cin >> N;
    // Bruteforce
    cout << minSteps1(N) << endl;

    // Memoization
    cout << minSteps2(N) << endl;

    // DP
    cout << minSteps3(N) << endl;
}