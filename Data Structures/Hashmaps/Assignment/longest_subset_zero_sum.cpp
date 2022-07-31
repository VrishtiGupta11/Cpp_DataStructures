#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int longestSubsetSum(int* arr, int N) {
    unordered_map<int, int> map;
    int maxLen = INT_MIN;
    // map[0] = 0;
    int sum = 0;
    if(arr[0] == 0)
        maxLen = 1;
    for(int i=0; i<N; i++) {
        sum += arr[i];
        if(i != 0) {
            if(map.count(sum) > 0) {
                maxLen = (i-map[sum]) > maxLen ? (i-map[sum]) : maxLen;
            }
            else {
                map[sum] = i;
            }
        }
        else {
            map[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cout << longestSubsetSum(arr, N) << endl;
}