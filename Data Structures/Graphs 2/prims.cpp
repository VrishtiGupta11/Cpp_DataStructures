#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

class Edge {
public:
    int source;
    int dest;
    int weight;
    Edge() {}
    Edge(int source, int dest, int weight) : source(source), dest(dest), weight(weight) {}
};

bool compare(int a, int b) {
    return a < b;
}

int getMinVertex(int weights[], bool visited[], int n) {
    int minVertex = n;
    int minWeight = INT_MAX;
    for(int i=0; i<n; i++) {
        if(weights[i] < minWeight && !visited[i]) {
            minWeight = weights[i];
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int n, vector<vector<int>> &edges) {
    int* parent = new int[n];
    int* weights = new int[n];
    bool* visited = new bool[n];
    sort(weights, weights+n, compare);
    for(int i=0; i<n; i++) {
        if(i == 0) {
            weights[i] = 0;
            parent[i] = -1;
            continue;
        }
        weights[i] = INT_MAX;
        visited[i] = false;
    }
    for(int i=0; i<n; i++) {
        int minVertex = getMinVertex(weights, visited, n);
        visited[minVertex] = true;
        for(int j=0; j<n; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                if(edges[minVertex][j] < weights[j]) {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i=1; i<n; i++) {
        cout << parent[i] << " " << i << " " << weights[i] << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges(n, vector<int>(n, 0));
    for(int i=0; i<e; i++) {
        int first, second, weight;
        cin >> first >> second >> weight;
        edges[first][second] = weight;
        edges[second][first] = weight;
    }

    cout << endl;
    prims(n, edges);
}