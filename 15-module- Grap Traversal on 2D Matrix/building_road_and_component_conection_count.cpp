#include <bits/stdc++.h>

using namespace std;
const int N =1e5+4;
bool visited[N];
vector<int>adj[N];
int n,m;

void bfs(int s)
{
    visited[s] =true;
    for (int v : adj[s])
    {
        if(!visited[v])
        {
            bfs(v);
        }
    }

}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans ;
    for (int i=1; i<=n ;i++)
    {
        if(!visited[i])
        {
            bfs(i);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for (int i=0; i<ans.size()-1;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}