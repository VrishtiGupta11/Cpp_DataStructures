#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int* arr, int N) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i=0; i<N; i++) {
        if(seen.count(arr[i]) > 0) {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    vector<int> output = removeDuplicates(arr, N);
    for(int i=0; i<output.size(); i++)
        cout << output[i] << " ";
}