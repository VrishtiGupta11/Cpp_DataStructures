#include <iostream>
using namespace std;

int CheckRotation(int arr[], int N) {
    for(int i=1; i<N; i++) {
        if(arr[i] < arr[i-1]) {
            return i;
        }
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cout << CheckRotation(arr, N);
}