#include <iostream>
#include <cstring>
using namespace std;

// Approach 1 - Brute force (O(2^n))
int fibonacci1(int N) {
    if(N <= 1) {
        return N;
    }
    return fibonacci1(N-1) + fibonacci1(N-2);
}

// Approach 2 - Memozation (Top-down approach) (Recursive) (O(n))
int helper1(int N, int* ans) {
    if(N <= 1) {
        return N;
    }
    if(ans[N] != -1) {
        return ans[N];
    }
    ans[N] = helper1(N-1, ans) + helper1(N-2, ans);
    return ans[N];
}

int fibonacci2(int N) {
    int* ans = new int[N+1];
    for(int i=0; i<=N; i++)
        ans[i] = -1;
    return helper1(N, ans);
}

// Approach 3 - Dynamic Programming (Bottom-Up approach) (Iterative) (O(n))

int fibonacci3(int N) {
    int* ans = new int[N+1]{-1};
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<N+1; i++) {
        ans[i] = ans[i-1] + ans[i-2];
    }
    return ans[N];
}

int main() {
    cout << "Fibonacci of 5: " << fibonacci1(5) << endl;
    cout << "Fibonacci of 6: " << fibonacci2(6) << endl;
    cout << "Fibonacci of 7: " << fibonacci3(7) << endl;
}