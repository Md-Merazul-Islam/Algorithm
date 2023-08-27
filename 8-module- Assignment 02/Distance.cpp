#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    visited[st] = true;
    // level[st] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        // if (u == end)
        // {
        //     return;
        // }
        for (int v : adj[u])
        {
            if (!visited[v])
            {

                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
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

    int t;
    cin >> t;
    while (t--)
    {
        int st, end;
        cin >> st >> end;
        bfs(st);

        if (visited[end])
        {
            cout << level[end] << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
        for (int i = 0; i <N; i++)
        {
            visited[i] = 0;
            level[i] = 0;
        }
    }
    return 0;
}