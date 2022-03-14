#include <iostream>
using namespace std;

bool SplitArray(int arr[], int size, int lsum, int rsum) {
    if(size == 0)
        return lsum == rsum;
    if(arr[0]%5 == 0) 
        lsum += arr[0];
    else if(arr[0]%3 == 0)
        rsum += arr[0];
    else
        return (SplitArray(arr+1, size-1, lsum+arr[0], rsum) || SplitArray(arr+1, size-1, lsum, rsum+arr[0]));
    return SplitArray(arr+1, size-1, lsum, rsum);
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    if(SplitArray(arr, N, 0, 0))
        cout << "True";
    else
        cout << "False";
}