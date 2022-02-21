#include <iostream>
using namespace std;

int SubsetSum(int arr[], int N, int num) {
    if(N == 0) {
        if(num == 0)
            return 1;
        else
            return 0;
    }
        
    int smallAns1 = SubsetSum(arr+1, N-1, num-arr[0]);
    int smallAns2 = SubsetSum(arr+1, N-1, num);
    return smallAns1+smallAns2;
}

int main() {
    int N, arr[100], num;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    cin >> num;
    cout << SubsetSum(arr, N, num);
}