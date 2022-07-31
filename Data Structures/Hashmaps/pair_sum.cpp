#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int* arr, int N) {
    unordered_map<int, int> map;
    int count = 0;
    for(int i=0; i<N; i++) {
        if(map.count((-1)*arr[i]) > 0) {
            for(int j=0; j<map[(-1)*arr[i]]; j++) {
                cout << arr[i] << " " << -arr[i] << endl;
                count++;
            }
        }
        map[arr[i]]++;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cout << pairSum(arr, N) << endl;
}