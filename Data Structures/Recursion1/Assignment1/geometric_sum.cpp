#include <iostream>
#include <cmath>
using namespace std;

float GeometricSum(int k) {
    if(k == 0) 
        return 1;
    float smallAns = GeometricSum(k-1);
    return smallAns + (1 / pow(2, k));
}

int main() {
    int k;
    cin >> k;
    cout << GeometricSum(k);
}