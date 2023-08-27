#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];// here declaire a list
void dfs (int parent)
{
    cout<<"visited Node :" << parent<<endl;
    visited[parent]=1;
    for (int child : adj[parent])
    {
        if(visited[child]==0)
        {
            depth[child] = depth[parent]+1;
            dfs(child);
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

    int search = 1;
    dfs(search);

    for (int i=1; i<=n; i++)
    {
        cout<<"Depth of Node "<<i<<": "<<depth[i]<<endl;
    }

    cout << "Depth of Node " <<  ": " << depth[5] << endl;

    return 0;
}