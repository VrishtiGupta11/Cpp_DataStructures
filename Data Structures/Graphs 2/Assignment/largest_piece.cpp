#include <iostream>
#include <vector>
using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &visited, int &counter) {
    counter++;
    visited[i][j] = 1;

    if(i-1 >= 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
        solve(i-1, j, n, grid, visited, counter);
    }

    if(j-1 >= 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
        solve(i, j-1, n, grid, visited, counter);    
    }
    
    if(i+1 <= n-1 && grid[i+1][j] == 1 && !visited[i+1][j]) {
        solve(i+1, j, n, grid, visited, counter);
    }
    
    if(j+1 <= n-1 && grid[i][j+1] == 1 && !visited[i][j+1]) {
        solve(i, j+1, n, grid, visited, counter);
    }
}

int largestPiece(int n, vector<vector<int>> &grid) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int counter;
    int maxi = 0;
    for(int i=0; i<n; i++) {    
        for(int j=0; j<n; j++) {
            counter=0;
            if(grid[i][j] == 1 && !visited[i][j]) {
                solve(i, j, n, grid, visited, counter);
                maxi = counter > maxi ? counter : maxi;
            }
        }
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << largestPiece(n, grid);
}