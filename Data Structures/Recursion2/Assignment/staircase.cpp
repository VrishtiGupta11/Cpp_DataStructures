#include <iostream>
using namespace std;

int StairCase(int N) {
    if(N == 0)
        return 1;
    if(N < 0)
        return 0;
    int x = StairCase(N-1);
    int y = StairCase(N-2);
    int z = StairCase(N-3);
    return x+y+z;
}

int main() {
    int N;
    cin >> N;
    cout << StairCase(N) << endl;
}