#include <iostream>
#include <cmath>
using namespace std;

// Bruteforce
int balancedBTs1(int h) {
    if(h == 0 || h == 1) {
        return 1;
    }
    int mod = (int) (pow(10, 9)) + 7;
    
    int x = balancedBTs1(h-1);
    int y = balancedBTs1(h-2);

    // Inorder to avoid out of range we have taken mod.
    // We have also taken long for individual multiplication
    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;
    return ans;
}

// Memoization
int helper(int h, int* arr) {
    if(h == 0 || h == 1) {
        return 1;
    }
    if(arr[h] != -1) {
        return arr[h];
    }
    int mod = (int) pow(10, 9) + 7;

    int x = helper(h-1, arr);
    int y = helper(h-2, arr);

    int temp1 = (int)(((long long)(x)*x) % mod);
    int temp2 = (int)((2*(long long)(x)*y) % mod);

    arr[h] = (temp1 + temp2)%mod;
    return arr[h];
}

int balancedBTs2(int h) {
    int* arr = new int[h+1];
    for(int i=0; i<=h; i++) {
        arr[i] = -1;
    }
    return helper(h, arr);
}

// DP
int balancedBTs3(int h) {
    int* arr = new int[h+1];
    arr[0] = 1;
    arr[1] = 1;
    int mod = (int) pow(10, 9) + 7;

    for(int i=2; i<=h; i++) {
        int x = arr[i-1];
        int y = arr[i-2];
        int temp1 = (int)(((long long)(x)*x) % mod);
        int temp2 = (int)((2*(long long)(x)*y) % mod);

        arr[i] = (temp1 + temp2)%mod;
    }
    return arr[h];
}

int main() {
    int h;
    cin >> h;

    // Bruteforce
    cout << balancedBTs1(h) << endl;

    // Memoization
    cout << balancedBTs2(h) << endl;

    // DP
    cout << balancedBTs3(h) << endl;
}