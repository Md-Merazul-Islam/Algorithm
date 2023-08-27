#include <bits/stdc++.h>

using namespace std;
const int N=1e5+5;
vector<int> adj[N];
bool visited[N];

void DFS(int u)
{
    //section 1: action just after entering noden u
    cout<<"Visiting node "<<u<<endl;
    visited[u] = true;

    for (int v: adj[u]) 
    {
        //section 2: actions before entering a new neighbor
        if(visited[v]== true) continue;
        DFS(v);
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
    // for (int i=1; i<=n;i++)
    // {
    //     cout<<"Node"<<i<<" : ";
    //     for (int j: adj[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    DFS(1);
    cout<<"Visited aray: "<<endl;
    for (int i=1; i<=n; i++)
    {
        cout<<"Node"<<i<<"status :"<< visited[i]<<endl;
    }
    return 0;
}