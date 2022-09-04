#include <iostream>
#include <vector>
using namespace std;

int f(int idx, int mini, vector<int> &arr) {
    if(idx == 0) {
        if(arr[idx] < mini) return 1;
        else return 0;
    }
    int pick = -1e9;
    if(arr[idx] < mini) pick = 1 + f(idx-1, arr[idx], arr);
    int notPick = f(idx - 1, mini, arr);
    return max(pick, notPick);
}

int LIS(int N, vector<int> &arr) {
    return f(N-1, 1e9, arr);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cout << LIS(N, arr);
}