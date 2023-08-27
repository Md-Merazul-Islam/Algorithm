#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;
vector<int> adj[N];
bool visited[N];
int parent[N];
bool dfs(int u,int p=-1) // p= parent [v er parent u , u er parent p]
{
    bool cycleExists = false;
    visited[u] = true;
    for (int v : adj[u])
    {
        if(v==p) continue;
        if (visited[v] == true)
            return true;
        cycleExists = cycleExists || dfs(v,u);
    }
    return cycleExists;
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
    // if(dfs(1,-1))
    // {
    //     cout<<"Cycle deteceted"<<endl;
    // }
    // else {
    //     cout<<"No cycle deteceted"<<endl;
    // }
    bool isCycle = false;
    for (int i=1; i<=n; i++)
    {
        if(visited[i])continue;
        
            isCycle |= dfs(i);
        
    }
    if(isCycle)
    {
        cout<<"Cycle deteceted"<<endl;
    }
    else {
        cout<<"No cycle deteceted"<<endl;
    }


   return 0;
}