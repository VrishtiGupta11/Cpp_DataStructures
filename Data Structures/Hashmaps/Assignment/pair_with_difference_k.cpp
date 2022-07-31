#include <iostream>
#include <unordered_map>
using namespace std;

int pairsWithDiffK(int* arr, int N, int k) {
    int count = 0;
    unordered_map<int, int> map;
    for(int i=0; i<N; i++) {
        if(map.count(arr[i]-k) > 0) {
            count += map[arr[i]-k];
            for(int l=0; l<map[arr[i]-k]; l++) 
                cout << arr[i] << " " << arr[i]-k << endl;
        }
        if(arr[i]-k != arr[i]+k) {
            if(map.count(arr[i]+k) > 0) {
                count += map[arr[i]+k];
                for(int l=0; l<map[arr[i]+k]; l++) 
                    cout << arr[i] << " " << arr[i]+k << endl;
            }
        }
        map[arr[i]]++;
    }
    return count;
}

int main() {
    int N, k;
    cin >> N;
    int* arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    cin >> k;
    int count = pairsWithDiffK(arr, N, k);
    cout << count << endl;
}