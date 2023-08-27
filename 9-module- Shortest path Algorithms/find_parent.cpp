#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int parent[N];
int shortest_path[N];

void bfs(int s) // o(n+m)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    shortest_path[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;

            q.push(v);
            visited[v] = true;
            parent[v] = u;
            shortest_path[v] = shortest_path[u] + 1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s, d;
    cin >> s >> d;
    bfs(s);
    for (int i = 1; i <= n; i++)
    {
        cout << "pareent " << i << " : " << parent[i] << endl;
    }

    
    // finding parent O(n) 
    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    // cout << "Shortest distance path : ";
    // cout << shortest_path[d] << endl;

    cout << "Path : ";
    for (int v : path)
    {
        cout << v << " ";
    }
    return 0;
}