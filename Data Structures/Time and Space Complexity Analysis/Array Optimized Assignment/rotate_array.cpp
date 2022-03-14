#include <iostream>
using namespace std;

void ReverseArray(int arr[], int start, int end) {
    for(int i=start, j=end; i<j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void RotateArray(int arr[], int N, int d) {
    ReverseArray(arr, 0, N-1);
    ReverseArray(arr, 0, N-d-1);
    ReverseArray(arr, N-d, N-1);
}

int main() {
    int N, d;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cin >> d;
    RotateArray(arr, N, d);
    for(int i=0; i<N; i++) 
        cout << arr[i] << " ";
}