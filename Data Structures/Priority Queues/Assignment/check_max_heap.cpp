#include <iostream>
// #include <queue>
using namespace std;

bool checkMaxHeap(int* arr, int N) {
    for(int i=0; 2*i+1 < N; i++) {
        if(arr[i] < arr[2*i + 1] || (2*i+2 < N && arr[i] < arr[2*i + 2])) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    bool ans = checkMaxHeap(arr, N);
    cout << (ans ? "True" : "False");
}