#include <iostream>
using namespace std;

void matrixRec(int M, int N, int i, int j, string str) {
    if(i == M || j == N) 
        return;
    if(i == M-1 && j == N-1) {
        cout << str << endl;
        return;
    }
    // Right
    matrixRec(M, N, i, j+1, str+"R");
    // Down
    matrixRec(M, N, i+1, j, str+"D");
}

int main() {
    int M, N;
    cin >> M >> N;
    matrixRec(M, N, 0, 0, "");
}