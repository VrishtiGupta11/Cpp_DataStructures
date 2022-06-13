#include <iostream>
using namespace std;

int countSubsets(int arr[], int N, int ind, int sum, int k) {
    if(ind == N) {
        if(sum%k == 0)
            return 1;
        else
            return 0;
    }
    int L = countSubsets(arr, N, ind+1, sum+arr[ind], k);
    int R = countSubsets(arr, N, ind+1, sum, k);
    return L+R;
}

int main() {
    int N, k;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    cin >> k;
    cout << countSubsets(arr, N, 0, 0, k)-1;
}