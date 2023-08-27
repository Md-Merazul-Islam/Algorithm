#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
vector<int> adj[N]; // Adjacency list
bool visited[N];    // Array to mark visited vertices

bool dfs(int u, int p = -1)
{
    bool cycleExist = false;
    visited[u] = true; // Mark current vertex as visited
    for (int v : adj[u])
    {
        if (v == p)
            continue; // Skip if v is parent of u (avoid backtracking)
        if (visited[v] == true)
            return true;                      // If v is visited and not parent, cycle found
        cycleExist = cycleExist || dfs(v, u); // Recurse on neighboring vertices
    }
    return cycleExist;
}

int main()
{
    int n, m;
    cin >> n >> m; // Read number of vertices and edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;       // Read an edge (u, v)
        adj[u].push_back(v); // Add v to u's adjacency list
        adj[v].push_back(u); // Add u to v's adjacency list (undirected graph)
    }

    bool isCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;                // Skip already visited vertices
        isCycle = isCycle || dfs(i); // Run DFS on unvisited vertices
    }

    // Output the result
    if (isCycle)
    {
        cout << "YES" << endl; // Cycle detected
    }
    else
    {
        cout << "NO" << endl; // No cycle detected
    }
    return 0;
}
