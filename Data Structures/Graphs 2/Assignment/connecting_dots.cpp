#include <iostream>
#include <vector>
using namespace std;

int counter = 0;

bool solve(int i, int j, int si, int sj, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &visited, char color) {
    // If there are atleast 4 color dots and if we are able to reach to starting index, i.e. a cycle of same colors then return true
    if(counter >= 4 && (i==si-1 || j == sj-1 || i==si+1 || j == sj+1)) return true;
    counter++;
    visited[i][j] = 1;
    bool ans = false;
    if(i-1 >= 0 && grid[i-1][j] == color && !visited[i-1][j]) {
        ans = solve(i-1, j, si, sj, n, m, grid, visited, color);
    }

    if(j-1 >= 0 && grid[i][j-1] == color && !visited[i][j-1]) {
        ans = solve(i, j-1, si, sj, n, m, grid, visited, color);
    }
    
    if(i+1 <= n-1 && grid[i+1][j] == color && !visited[i+1][j]) {
        ans = solve(i+1, j, si, sj, n, m, grid, visited, color);
    }
    
    if(j+1 <= m-1 && grid[i][j+1] == color && !visited[i][j+1]) {
        ans = solve(i, j+1, si, sj, n, m, grid, visited, color);
    }
    visited[i][j] = 0;
    return ans;
}

bool connectingDots(int n, int m, vector<vector<char>> &grid) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            counter=0;
            bool ans = solve(i, j, i, j, n, m, grid, visited, grid[i][j]);
            if(ans) return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << (connectingDots(n, m, grid) ? "true" : "false");
}

/*

7 6
AAAAAB
ABBBAB
ABAAAB
ABABBB
ABAAAB
ABBBAB
AAAAAB

output - true

*/