#include<iostream>
using namespace std;

int BinarySearch(int arr[], int N, int toSearch){
    int start=0, end = N-1, mid;
    while (start <= end)
    {
        mid = (start+end)/2;
        if(arr[mid] == toSearch)
            return mid;
        else if (toSearch > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int N, arr[100], x, position;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    cin>>x;
    
    position = BinarySearch(arr, N, x);
    if(position == -1)
        cout<<"Element not found\n";
    else
        cout<<"Element found at position "<<position + 1;
}