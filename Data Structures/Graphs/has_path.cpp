#include <iostream>
#include <vector>
using namespace std;

bool hasPath(int N, vector<vector<int>> &edges, int sv, int ev, vector<int> &visited) {
    visited[sv] = 1;
    if(edges[sv][ev] == 1) {
        return true;
    }
    int i=0;
    for(; i<N; i++) {
        if(edges[sv][i] == 1 && !visited[i]) {
            bool ans = hasPath(N, edges, i, ev, visited);
            return ans;
        }
    }
    if(i == N) return false;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for(int i=0; i<e; i++) {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
    vector<int> visited(n, 0);
    int sv, ev;
    cin >> sv >> ev;
    cout << (hasPath(n, edges, sv, ev, visited) ? "True" : "False");
}