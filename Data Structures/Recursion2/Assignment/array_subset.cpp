#include <iostream>
using namespace std;

int Subset(int arr[], int size, int output[][100]) {
    if(size == 0) {
        output[0][0] = 0;
        return 1;
    }
    int smallAns = Subset(arr + 1, size - 1, output);

    for(int i=0; i<smallAns; i++) {
        output[i+smallAns][0] = output[i][0]+1;
        output[i+smallAns][1] = arr[0];
        for(int j=1; j <= output[i][0]; j++) {
            output[i + smallAns][j+1] = output[i][j];
        }
    }
    return 2*smallAns;
}

int main() {
    int N, outputSize;
    cin >> N;
    int* arr = new int[N];
    int output[100][100];
    for(int i=0; i<N; i++) 
        cin >> arr[i];
    outputSize = Subset(arr, N, output);
    for(int i=0; i<outputSize; i++) {
        for(int j=1; j<output[i][0]+1; j++) 
            cout << output[i][j] << " ";
        cout << endl;
    }
}