#include <iostream>
#include <algorithm>
using namespace std;

class Edge {
public:
    int source;
    int dest;
    int weight;
    Edge() {}
    Edge(int source, int dest, int weight) : source(source), dest(dest), weight(weight) {}
};

int findParent(int v, int parent[]) {
    // To find top most parent
    if(parent[v] == v) return v;
    return findParent(parent[v], parent);
}

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskals(int n, int e, Edge* input) {
    // Sorting edges on the basis of increasing weight
    sort(input, input+e, compare);

    // Output array consisting of MST edges
    Edge* output = new Edge[n-1];
    
    // Parent array, initially every element is its own parent i.e. individual components, none are connected
    int* parent = new int[n];
    for(int i=0; i<n; i++)
        parent[i] = i;

    // We will add n-1 edges in our output
    int count = 0;
    int i=0;
    while(count < n-1) {
        // Considering 1st edge of the graph
        Edge currentEdge = input[i];

        // finding top most parent of source and destination vertices
        int p1 = findParent(currentEdge.source, parent);
        int p2 = findParent(currentEdge.dest, parent);

        // If two parents are not equal that means they belong to different components, therefore, we can add this edge in our output array
        // After adding edge, we are making parents same
        if(p1 != p2) {
            output[count++] = currentEdge;
            parent[p1] = p2;
        }
        i++;
    }

    for(int i=0; i<count; i++) {
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    Edge* input = new Edge[e];
    
    for(int i=0; i<e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i] = Edge(s, d, w);
    }
    
    kruskals(n, e, input);
}