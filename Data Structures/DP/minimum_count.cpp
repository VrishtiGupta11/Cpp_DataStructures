#include <iostream>
#include <cmath>
using namespace std;

// Bruteforce
int minimumCount1(int N) {
    if(N == 0) 
        return 0;
    int ans=1;
    for(int i=1; i<=sqrt(N); i++) {
        ans = 1+min(ans, minimumCount1(N-(i*i)));
    }
    return ans;
}

// Memoization
int helper2(int N, int* arr) {
    if(N == 0) {
        return 0;
    }
    if(arr[N] != -1)
        return arr[N];
    int ans = 1;
    for(int i=1; i<=sqrt(N); i++) {
        ans = 1 + min(ans, helper2(N-(i*i), arr));
    }
    arr[N] = ans;
    return ans;
}

int minimumCount2(int N) {
    int* arr = new int[N+1];
    for(int i=0; i<=N; i++)
        arr[i] = -1;
    return helper2(N, arr);
}

// DP
int minimumCount3(int N) {
    int* arr = new int[N+1];
    arr[0] = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=sqrt(N); j++) {
            if(i - j*j >= 0) {
                arr[i] = min(arr[i], 1+arr[i-j*j]);
            }
        }
    }
    return arr[N];
}

int main() {
    int N;
    cin >> N;

    // Bruteforce
    cout << minimumCount1(N) << endl;

    // Memoization
    cout << minimumCount2(N) << endl;

    // DP
    cout << minimumCount3(N) << endl;
}