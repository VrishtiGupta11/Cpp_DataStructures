#include<iostream>
using namespace std;

int LastOccurenceIndex(int arr[], int size, int X) {
    if(size == 0)
        return -1;
    if(arr[size - 1] == X)
        return (size - 1);
    int smallOutput = LastOccurenceIndex(arr, size-1, X);
    return (smallOutput == -1 ? -1 : smallOutput);
}

int main() {
    int N, X;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> X;
    cout << LastOccurenceIndex(arr, N, X);
}