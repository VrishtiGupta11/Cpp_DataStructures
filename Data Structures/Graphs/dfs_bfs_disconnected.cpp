#include <iostream>
#include <vector>
#include <queue>
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

void dfs(vector<vector<int>> &edges, int n) {
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) 
        if(!visited[i])
            printdfs(edges, n, i, visited);
}

void printbfs(vector<vector<int>> &edges, int n, int sv, vector<bool> &visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()) {
        int frontVertex = q.front();
        cout << frontVertex << " ";
        q.pop();
        for(int i=0; i<n; i++) {
            if(visited[i]) continue;
            if(edges[frontVertex][i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(vector<vector<int>> &edges, int n) {
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) 
        if(!visited[i])
            printbfs(edges, n, i, visited);
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

    bfs(edges, n);
    cout << endl;
    dfs(edges, n);
}