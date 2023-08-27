#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    int distand;
    typedef pair<int, int> pii;
    bool visited = false;
    pii last;

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isvalid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void bfs(vector<vector<int>>& grid) {
        queue<pii> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            for (auto d : dir) {
                int new_row = u.first + d.first;
                int new_col = u.second + d.second;

                if (isvalid(new_row, new_col) && grid[new_row][new_col] == 0) {
                    q.push({new_row, new_col});
                    grid[new_row][new_col]=grid[ u.first][u.second]+1;;
                    visited = true;
                    last = {new_row, new_col};
                }
            }
        }
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        bfs(grid);

        if (!visited) {
            return -1;
        } else {
            return grid[last.first][last.second] - 1;
        }
    }
};


//-------------------------------------------------------->

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    typedef pair<int, int> pii;
    pii last;
    
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isvalid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(vector<vector<int>>& grid, int row, int col) {
        if (!isvalid(row, col) || grid[row][col] != 0) {
            return;
        }

        grid[row][col] = 1; // Mark as visited
        last = {row, col};

        for (auto d : dir) {
            int new_row = row + d.first;
            int new_col = col + d.second;
            dfs(grid, new_row, new_col);
        }
    }

    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                }
            }
        }

        if (last.first == 0 && last.second == 0) {
            return -1;
        } else {
            return grid[last.first][last.second] - 1;
        }
    }
};
