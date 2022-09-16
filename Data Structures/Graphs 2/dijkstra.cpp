#include <iostream>
#include<climits>
#include <vector>
using namespace std;

int getMInVertex(vector<int> distance, vector<int> visited, int n) {
    int minVertex = n;
    int minDist = INT_MAX;
    for(int i=0; i<n; i++) {
        if(distance[i] < minDist && !visited[i]) {
            minVertex = i;
            minDist = distance[i];
        }
    }
    return minVertex;
}

void dijkstra(int n, vector<vector<int>> &edges, int sv) {
    vector<int> visited(n, 0);
    vector<int> distance(n, INT_MAX);
    distance[sv] = 0;

    // for each vertex, get min distance vertex which is not yet visited
    // mark that as visited and explore all its neighbors and update accordingly
    for(int i=0; i<n; i++) {
        int minVertex = getMInVertex(distance, visited, n);
        visited[minVertex] = 1;
        // Now exploring all the neighbours of minVertex
        for(int j=0; j<n; j++) {
            if(edges[minVertex][j] != 0 && !visited[j]) {
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]) {
                    distance[j] = dist;
                }
            }
        }
    }

    cout << "Min distance of " << sv << " to all the vertices: " << endl;
    for(int i=0; i<n; i++) {
        cout << distance[i] << " ";
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
    dijkstra(n, edges, 0);
}