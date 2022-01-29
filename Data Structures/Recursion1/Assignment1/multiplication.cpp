#include<iostream>
using namespace std;

int Multiplication(int M, int N) {
    if(M > N) {
        int temp = M;
        M = N;
        N = temp;
    }
    if(M == 0)
        return M;
    if(M == 1)
        return N;
    int smallAns = Multiplication(M-1, N);
    return N + smallAns;
}

int main() {
    int M, N;
    cin >> M >> N;
    cout << Multiplication(M, N);
}

// God is improving my functionality by trying all possible test Cases so that I can function better in similar test Cases if found in future and can be empathetic if anyone else faces similar testCase.
// So face these test cases with smile on your face, not with the attitude of why me.
// Have faith in GOD. He is the Almighty.