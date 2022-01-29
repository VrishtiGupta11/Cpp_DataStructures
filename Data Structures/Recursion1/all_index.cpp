#include<iostream>
using namespace std;

// Approach 1 - We will solve for first part and rest n-1 parts will be solved through recursion.
int allOccurenceIndex1(int arr[], int size, int X, int output[]) {
    if (size == 0)
        return 0;
    int smallOutput = allOccurenceIndex1(arr + 1, size - 1, X, output);
    if(arr[0] == X) {
        for(int i = smallOutput - 1; i >= 0; i--) {
            output[i+1] = output[i] + 1;
        }
        output[0] = 0;
        return smallOutput+1;
    }
    for(int i = smallOutput - 1; i >= 0; i--) {
        output[i]++;
    }
    return smallOutput;
}

// Approach 2 - Recursion will work on first n-1 parts and we will work on last part.
int allOccurenceIndex2(int arr[], int size, int X, int output[]) {
    if (size == 0)
        return 0;
    int smallOutput = allOccurenceIndex2(arr, size - 1, X, output);
    if(arr[size - 1] == X) {
        output[smallOutput] = size - 1;
        return smallOutput+1;
    }
    return smallOutput;
}


int main() {
    int N, X, output[100], outputSize;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> X;
    // outputSize = allOccurenceIndex1(arr, N, X, output);
    outputSize = allOccurenceIndex2(arr, N, X, output);
    for(int i=0; i<outputSize; i++)
        cout << output[i] << " ";
}