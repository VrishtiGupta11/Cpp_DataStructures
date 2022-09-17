#include <iostream>
#include <vector>
using namespace std;

bool reachString(int idx, string str, int i, int j, int m, int n, vector<vector<char>> &grid, vector<vector<int>> &visited) {
    if(idx >= str.size()){
        return true;
    }
    visited[i][j] = 1;

    bool ans = false;

    if(i-1 >= 0 && grid[i-1][j] == str[idx] && !visited[i-1][j]) {
        ans = ans || reachString(idx + 1, str, i-1, j, m, n, grid, visited);
    }

    if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == str[idx] && !visited[i-1][j-1]) {
        ans = ans || reachString(idx + 1, str, i-1, j-1, m, n, grid, visited);
    }

    if(i-1 >= 0 && j+1 <= n-1 && grid[i-1][j+1] == str[idx] && !visited[i-1][j+1]) {
        ans = ans || reachString(idx + 1, str, i-1, j+1, m, n, grid, visited);
    }

    if(j-1 >= 0 && grid[i][j-1] == str[idx] && !visited[i][j-1]) {
        ans = ans || reachString(idx + 1, str, i, j-1, m, n, grid, visited);
    }

    if(j+1 <= n-1 && grid[i][j+1] == str[idx] && !visited[i][j+1]) {
        ans = ans || reachString(idx + 1, str, i, j+1, m, n, grid, visited);
    }

    if(i+1 <= m-1 && grid[i+1][j] == str[idx] && !visited[i+1][j]) {
        ans = ans || reachString(idx + 1, str, i+1, j, m, n, grid, visited);
    }

    if(i+1 <= m-1 && j-1 >= 0 && grid[i+1][j-1] == str[idx] && !visited[i+1][j-1]) {
        ans = ans || reachString(idx + 1, str, i+1, j-1, m, n, grid, visited);
    }

    if(i+1 <= m-1 && j+1 <= n-1 && grid[i+1][j+1] == str[idx] && !visited[i+1][j+1]) {
        ans = ans || reachString(idx + 1, str, i+1, j+1, m, n, grid, visited);
    }

    visited[i][j] = 0;
    return ans;
}

bool solve(vector<vector<char>> &grid, int m, int n) {
    string str = "CODINGNINJA";
    vector<vector<int>> visited(m, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            bool ans = false;
            if(grid[i][j] == str[0]){
                ans = reachString(1, str, i, j, m, n, grid, visited);
                if(ans){
                    return 1; 
                }
                // for(int i=0; i<m; i++){
                //     for(int j=0; j<n; j++){
                //         visited[i][j] = 0;
                //     }
                // }
            }
    
        }
    }
    return 0;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << (solve(grid, m, n) ? 1 : 0);
}

/*
3 6
CXNAXC
OIJNOD
DXNGIX

Output - 
1


2 11
CXDXNXNXNXA
XOXIXGXIXJX

Output-
1
*/