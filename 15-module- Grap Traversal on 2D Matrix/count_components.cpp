#include <bits/stdc++.h>

using namespace std;

const int N =1e5+4;
bool visited[N];
int dist[N];
vector<int>adj[N];
vector<int> cmp;
void dfs(int s)
{
    visited[s]=true;
    cmp.push_back(s);

    for(int child : adj[s])
    {
        if(!visited[child])
        {
            dfs(child);
            visited[child]=true;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(i);

            for (int c : cmp)
            {
                cout<<c<<" ";
            }
            cout<<endl;
            cmp.clear();// must be 
        }
    }
    cout<<cnt;
    return 0;
}