#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
vector<int> adj[N];
vector<bool> visited(N+1, false);

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
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

    vector<int> leader;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        leader.push_back(i);
        dfs(i);
    }
    // for (auto l : leader)
    // {
    //     cout << l << " ";
    // }

    cout<<leader.size()-1<<endl;
    for (int i=1; i<leader.size(); i++)
    {
        cout<<leader[i-1]<<" "<<leader[i]<<endl;
    }
    return 0;
}