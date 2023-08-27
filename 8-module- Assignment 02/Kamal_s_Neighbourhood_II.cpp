#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3;
vector<int> adj[N];
bool visited[N];
int dfs(int u)
{
    int cnt = 0;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
            continue;
        visited[v] = true;
        cnt = cnt + dfs(v);
        cnt++;
    }
    return cnt;
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
    }

    int t;
    cin >> t;
    int ans = dfs(t);
    cout << ans << endl;
    return 0;
}