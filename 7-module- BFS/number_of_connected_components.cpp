#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;
vector<int> adj[N];
bool visited[N];
int level[N];
queue<int> q;

void bfs(int s)
{
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if(visited[v]==0)
            q.push(v);
            visited[v] = true;
        }
    }
}


void dfs(int u)
{

    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
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

    int conneceted_componented=0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        dfs(i);
        conneceted_componented++;
    }

    cout << "Number of connected componented : " << conneceted_componented << endl;


    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == true)
            continue;
        bfs(i);
        conneceted_componented++;
    }

    cout << "Number of connected componented : " << conneceted_componented << endl;
    return 0;
}