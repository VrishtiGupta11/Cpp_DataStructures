#include<iostream>
using namespace std;

void PrintNumbers(int N){
    if(N == 0)
        return;
    PrintNumbers(N-1);
    cout << N << " ";
}

int main() {
    int N;
    cin >> N;
    PrintNumbers(N);
}