#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
queue<int> q;
bool visited[N];

void bfs(int s)
{
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << "visited Node : " << u << endl;
        for (int v : adj[u])
        {
            if (visited[v] == 0)
            {
                q.push(v);
                visited[v] = true;
            }
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

    bfs(1);

    return 0;
}
