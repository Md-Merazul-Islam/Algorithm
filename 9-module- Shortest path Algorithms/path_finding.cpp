
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;
vector<int> adj[N];
bool visited[N];
int parent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s]=-1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])

        {
            if (visited[v])
                continue;
            visited[v] = true;
            parent[v] = u;
            q.push(v);
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
    int current = d;
    vector<int> path;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << " path : ";
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}