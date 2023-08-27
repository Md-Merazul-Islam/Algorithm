#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 2;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
    bfs(0);

    bool shop_find = false;
    if (t == 0)
    {
        cout << "0";
    }
    else
    {

        for (int i = 0; i < N; i++)
        {

            if (level[i] == t)
            {
                shop_find = true;
                cout << i << " ";
            }
        }
        if (shop_find != 1)
        {

            cout << "-1" << endl;
        }
    }

    return 0;
}


