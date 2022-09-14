#include <iostream>
#include <vector>
using namespace std;

void isConnected(int N, int sv, vector<vector<int>> &edges, vector<int> &visited) {
    if(N == 0) return;
    
    visited[sv] = 1;
    // cout << ">>> isConnected1" << endl;
    for(int i=0; i<N; i++) {
        // cout << ">>> isConnected2" << endl;
        if(edges[sv][i] && !visited[i]) {
            isConnected(N, i, edges, visited);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    
    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<int> visited(n, 0);
    // cout << ">>> Main1" << endl;
    isConnected(n, 0, edges, visited);
    // cout << ">>> Main2" << endl;
    int i=0;
    for(; i<n; i++) {
        if(visited[i] == 0) {
            cout << "false";
            break;
        }
    }
    if(i == n) 
        cout << "true";
}