#include <bits/stdc++.h>

using namespace std;

const int N= 1e3+5;
vector<int> adj[N];
bool visited[N];
int shortest_path[N];


void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    shortest_path[s]=0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if(visited[v])continue;
            q.push(v);
            visited[v]=true;
            shortest_path[v]=shortest_path[u]+1;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<<"Shortest path : ";
    cout<<shortest_path[d]<<endl;
    return 0;
}