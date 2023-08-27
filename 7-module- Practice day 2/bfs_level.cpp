#include <bits/stdc++.h>

using namespace std;

const int N= 1e3+3;
vector<int> adj[N];
bool visited[N];
queue<int>q;

int level[N];
void bfs(int s)
{
    q.push(s);
    visited[s]= true;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for ( int v : adj[u])
        {
            if(visited[v]== true) continue;
            q.push(v);
            visited[v]=true;
            level[v] = level[u]+1;
        }
    }

}
int main()
{
    int n,m;
    cin>>n>>m; 
    for ( int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int t;cin>>t;

    bfs(1);
    cout<<"Level of "<<t<<" = "<<level[t]<<endl;

    return 0;
}