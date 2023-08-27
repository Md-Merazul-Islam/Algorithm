#include <bits/stdc++.h>

using namespace std;

const int N= 1e3+5;
vector<int> adj[N];
bool visited [N];

void dfs(int u)
{
    visited[u]= true;
    for (int v : adj[u])
    {
        if ( visited[v]) continue;
        dfs(v);
        visited[v]= true;
    }
}

void bfs ( int s)
{
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v]=true;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cc=0;

    for (int i=1; i<=n; i++)
    {
        if (visited[i]) continue;
        dfs(i);
        bfs(i);
        cc++;
    }
    cout<<"DFS OUTPUT : "<<cc<<endl;
    cout<<"BFS OUTPUT : "<<cc<<endl;
    return 0;
}