#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void reverseArray(int arr[], int N, int ind) {
    if(ind >= N/2) 
        return;
    swap(arr[ind], arr[N-ind-1]);
    reverseArray(arr, N, ind+1);
}

int main() {
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    reverseArray(arr, N, 0);
    for(int i=0; i<N; i++)
        cout << arr[i] << " ";
}