#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int *arr1, int *arr2, int N1, int N2) {
    unordered_map<int, int> map;
    for(int i=0; i<N1; i++) 
        map[arr1[i]]++;
    for(int j=0; j<N2; j++) {
        map[arr2[j]]--;
        if(map[arr2[j]] >= 0)
            cout << arr2[j] << " ";
    }

}

int main() {
    int N1, N2;
    cin >> N1;
    int* arr1 = new int[N1];
    for(int i=0; i<N1; i++)
        cin >> arr1[i];
    cin >> N2;
    int* arr2 = new int[N2];
    for(int i=0; i<N2; i++)
        cin >> arr2[i];
    printIntersection(arr1, arr2, N1, N2);
}