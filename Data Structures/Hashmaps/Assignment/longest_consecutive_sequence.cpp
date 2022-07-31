#include <iostream>
#include <unordered_map>
using namespace std;

class Pair {
public:
    int start;
    int maxLen;
};

Pair longestConsecutiveSequence(int* arr, int N) {
    unordered_map<int, bool> map;
    Pair p;
    p.maxLen = 0;
    p.start = arr[0];
    for(int i=0; i<N; i++) 
        map[arr[i]] = true;
    for(int i=0; i<N; i++) {
        int j=1, k=1, count=1;
        if(map[arr[i]] == true) {
            while(map.count(arr[i] + j) > 0) {
                map[arr[i] + j] = false;
                j++;
                count++;
            }
            while(map.count(arr[i] - k) > 0) {
                map[arr[i] - k] = false;
                k++;
                count++;
            }
        }
        if(count > p.maxLen) {
            p.start = arr[i] - k + 1;
            cout << p.start << endl;
            p.maxLen = count;
        }
    }
    return p;
}

int main() {
    int N;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    Pair p = longestConsecutiveSequence(arr, N);
    cout << p.start << " " << p.start + p.maxLen -1 << endl;
}