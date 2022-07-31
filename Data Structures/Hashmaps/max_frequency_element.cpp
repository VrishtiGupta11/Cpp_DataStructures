#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxFrequency(int* arr, int N) {
    unordered_map<int, int> map;
    vector<int> output;
    for(int i=0; i<N; i++) {
        if(map.count(arr[i]) == 0) {
            output.push_back(arr[i]);
        }
        ++map[arr[i]];
    }
    int maxi = output[0];
    for(int i=1; i<output.size(); i++) {
        if(map[output[i]] > map[maxi]) {
            maxi = output[i];
        }
    }
    return maxi;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cout << maxFrequency(arr, N) << endl;
}