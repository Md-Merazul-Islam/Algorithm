#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 1;
vector<int> adj[N];
bool visited[N];

vector<int> ans;
void dfs(int u)
{
    ans.push_back(u);
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

    dfs(1);
    for (int i = ans.size(); i > 0; i--)
    {
        cout << i << " ";
    }
    return 0;
}