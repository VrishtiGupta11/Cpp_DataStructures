#include <iostream>
using namespace std;

int SubsetSum(int arr[], int N, int k, int output[100][100]) {
    int output1[100][100];
    if(N == 0) {
        if(k == 0) {
            output[0][0] = 0;
            return 1;
        }
        else
            return 0;
    }
    int smallAns1 = SubsetSum(arr+1, N-1, k, output);
    int smallAns2 = SubsetSum(arr+1, N-1, k-arr[0], output1);

    for(int i=0; i<smallAns2; i++) {
        for(int j=2; j<=output1[i][0]+1; j++) 
            output[smallAns1 + i][j] = output1[i][j-1];
        output[i+smallAns1][0] = output1[i][0]+1;
        output[i+smallAns1][1] = arr[0];
    }
    return smallAns1+smallAns2;
}

int main() {
    int N, k, arr[100], output[100][100], outputSize;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> k;
    outputSize = SubsetSum(arr, N, k, output);
    for(int i=0; i<outputSize; i++) {
        for(int j=1; j<=output[i][0]; j++)
            cout << output[i][j] << " ";
        cout << endl;
    }
}