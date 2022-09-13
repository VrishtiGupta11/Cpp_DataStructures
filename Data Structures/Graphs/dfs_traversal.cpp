#include <iostream>
#include <vector>
using namespace std;

void printdfs(vector<vector<int>> &edges, int n, int sv, vector<bool> &visited) {
    cout << sv << " ";
    visited[sv] = true;
    for(int i=0; i<n; i++) {
        if(visited[i]) continue;
        if(edges[sv][i] == 1) 
            printdfs(edges, n, i, visited);
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    vector<bool> visited(n, false);

    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    printdfs(edges, n, 0, visited);
}