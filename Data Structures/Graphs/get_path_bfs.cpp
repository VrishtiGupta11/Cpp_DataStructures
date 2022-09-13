#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void getPathBFS(int N, vector<vector<int>> &edges, vector<int> &visited, int sv, int ev, unordered_map<int, int> &map) {
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    while(q.front() != ev && !q.empty()) {
        int front = q.front();
        q.pop();

        for(int i=0; i<N; i++) {
            if(edges[front][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = 1;
                // cout << front << " ";
                map[i] = front;
            }
        }
    }
    if(map.count(ev) > 0) {
        // cout << "If there exist end vertex int map then print path" << endl;
        while(ev != sv) {
            cout << ev << " ";
            ev = map[ev];
        }
        cout << ev;
    }
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
    unordered_map<int, int> map;
    getPathBFS(n, edges, visited, sv, ev, map);
}