#include <iostream>
#include <vector>
using namespace std;

// Count No. of connected islands
void island(int sv, int n, vector<vector<int>> &edges, vector<int> &visited) {
    visited[sv] = 1;
    for(int i=0; i<n; i++) {
        if(edges[sv][i] == 1 && !visited[i]) 
            island(i, n, edges, visited);
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<int> visited(n, 0);
    int count = 0;

    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            count++;
            island(i, n, edges, visited);
        }
    }
    cout << count;
}