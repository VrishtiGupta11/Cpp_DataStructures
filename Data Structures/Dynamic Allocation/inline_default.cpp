#include<iostream>
using namespace std;

// Inline
inline int Max(int a, int b) {
    return (a > b) ? a : b;
}

// Default Argument
int Sum(int arr[], int size, int si = 0) {
    int ans = 0;
    while(si < size) {
        ans += arr[si++];
    }
    return ans;
}

int main() {
    int a, b, N;
    /*
    cin >> a >> b;
    cout << Max(a, b);
    */
    cin >> N;
    int *arr = new int[N];

    for(int i=0; i<N; i++) {
        cin >> *(arr + i);
    }

    Sum(arr, N); // If we dont pass argument, starting index is by default 0.
}