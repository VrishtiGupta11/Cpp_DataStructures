#include<iostream>
using namespace std;

void increment(int* arr, int N){
    for(int i=0; i<N; i++){
        arr[i]++;
    }
}

int main() {
    int testCases, N;
    cin>>testCases;
    int **p = new int* [testCases];
    int *testCasesSize = new int[testCases];
    for(int i=0; i<testCases; i++){
        cin>>N;
        p[i] = new int[N];
        testCasesSize[i] = N;
        for(int j=0; j<N; j++){
            cin>>p[i][j];
        }
        increment(*(p+i), N);
    }
    cout<<endl;
    for(int i=0; i<testCases; i++) {
        for (int j = 0; j < testCasesSize[i]; j++) {
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}

// int main() {
//     int N, M;
//     cin>>N>>M;
//     int** p = new int*[10];
//     for (int i = 0; i < N; i++) {
//         p[i] = new int[M];
//         for (int j = 0; j < M; j++) {
//             cin>>p[i][j];
//         }
//     }
//     for(int i=0; i<N; i++){
//         for(int j=0; j<M; j++)
//             cout<<p[i][j]<<" ";
//         cout<<endl;
//     }
//     for(int i=0; i<N; i++){
//         delete [] p[i];
//     }
//     delete [] p;
// }