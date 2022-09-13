#include <iostream>
#include <vector>
using namespace std;

void getPath(int N, vector<vector<int>>& edges, int sv, int ev, vector<int> &visited, vector<int> &output) {
    visited[sv] = 1;
    if(sv == ev) {
        output.push_back(ev);
        return;
    }
    for(int i=0; i<N; i++) {
        if(edges[sv][i] == 1 && !visited[i]) {
            getPath(N, edges, i, ev, visited, output);
            if(output.size() > 0) {
                output.push_back(sv);
                return;
            }
        }
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
    vector<int> output;
    int sv, ev;
    cin >> sv >> ev;
    getPath(n, edges, sv, ev, visited, output);
    for(int i=0; i<output.size(); i++) 
        cout << output[i] << " ";
}