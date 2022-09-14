#include <iostream>
#include <vector>
using namespace std;

void helper(int sv, int N, vector<vector<int>> &edges, vector<int> &visited, vector<int> &output) {
    visited[sv] = 1;
    output.push_back(sv);
    for(int i=0; i<N; i++) {
        if(edges[sv][i] == 1 && !visited[i]) {
            helper(i, N, edges, visited, output);
        }
    }
}

vector<vector<int>> allConnectedComponents(vector<vector<int>> &edges, int N) {
    vector<int> visited(N, 0);
    vector<vector<int>> output;
    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            vector<int> component;
            helper(i, N, edges, visited, component);
            output.push_back(component);
        }
    }
    return output;
}

int main() {
    int N, e;
    cin >> N >> e;
    vector<vector<int>> edges(N, vector<int>(N, 0));
    
    for(int i=0; i<e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<vector<int>> output = allConnectedComponents(edges, N);
    for(int i=0; i<output.size(); i++) {
        for(int j=0; j<output[i].size(); j++) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}