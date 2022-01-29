#include<iostream>
using namespace std;

int Sum(int arr[], int N) {
    if (N == 0)
        return 0;
    if (N == 1)
        return arr[0];
    int smallOutput = arr[0] + Sum(arr+1, N-1);
    return smallOutput;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cout << Sum(arr, N);
}