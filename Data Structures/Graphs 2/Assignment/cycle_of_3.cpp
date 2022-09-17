#include <iostream>
#include <vector>
using namespace std;

// int f(int sv, int v, int n, vector<vector<int>> &edges, vector<int> &visited, int count) {
//     visited[sv] = 1;
//     count++;
//     if(count == 3) {
//         if(edges[sv][v] == 1) return 1;
//         else return 0;
//     }

//     for(int i=0; i<n; i++) {
//         if(edges[sv][i] == 1 && !visited[i]) {
//             return f(i, v, n, edges, visited, count);
//         }
//     }
//     return 0;
// }

// int cycle3(vector<vector<int>> &edges, int n) {
//     vector<int> visited(n, 0);
//     int ans = 0;
//     for(int i=0; i<n; i++) {
//         if(!visited[i]) {
//             ans += f(i, i, n, edges, visited, 0);
//         }
//     }
//     return ans;
// }


// Above code is not working for this test case
// 6 9
// 4 3
// 4 0
// 0 3
// 3 1
// 5 1
// 5 3
// 0 5
// 0 2
// 5 2

// output = 4

int cycle3(vector<vector<int>> &edges, int n) {
    vector<int> visited(n, 0);
    int count=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(edges[i][j]) {
                for(int k=0; k<n; k++) {
                    if(edges[j][k]) {
                        if(edges[i][k]) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    // in cycle of 3, all three vertices leads to same cycle, since we have not kept visited
    // by keeping visited we will not be able to track other 3-cycles, if common vertices b/w two cycles
    // e.g. => 1-2-4-1, 1-4-2-1 / 2-4-1-2 / 2-1-4-2 / 4-1-2-4 / 4-2-1-4 => these all should be treated as single cycle
    return count/6;
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

    cout << cycle3(edges, n);
}