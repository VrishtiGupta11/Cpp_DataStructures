#include<iostream>
using namespace std;

int FirstOccurenceIndex(int arr[], int size, int X, int N) {
    if(size == 0)
        return -1;
    if(arr[0] == X)
        return N-size;
    return FirstOccurenceIndex(arr+1, size-1, X, N);
}

int FirstOccurenceIndex1(int arr[], int size, int X) {
    if(size == 0)
        return -1;
    if(arr[0] == X)
        return 0;
    int smallOutput = FirstOccurenceIndex1(arr+1, size-1, X);
    return (smallOutput == -1 ? -1 : 1+smallOutput);
}

int main() {
    int N, X;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> X;
    // cout << FirstOccurenceIndex(arr, N, X, N);
    cout << FirstOccurenceIndex1(arr, N, X);
}