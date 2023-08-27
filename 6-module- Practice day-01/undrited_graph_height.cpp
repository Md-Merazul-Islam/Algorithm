#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
vector<int> adj[N];
bool visited[N];
int height[N];

void dfs(int u)
{

    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == 0)
        {
            dfs(v);
            height[u] = max(height[u], height[v] + 1);
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
    int test;
    cin >> test;

    dfs(1);

    cout << "Height of " << test << " = " << height[test] << endl;
    return 0;
}
