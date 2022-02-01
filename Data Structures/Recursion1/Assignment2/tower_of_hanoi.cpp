#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char s, char a, char d) {
    if(n == 1) {
        cout << s << "->" << d << endl;
        return;
    }
    TowerOfHanoi(n-1, s, d, a);
    cout << s << "->" << d << endl;
    TowerOfHanoi(n-1, a, s, d);
}

int main() {
    int n;
    cin >> n;
    TowerOfHanoi(n, 'a', 'b', 'c');
}