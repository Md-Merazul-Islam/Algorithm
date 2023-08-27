#include <bits/stdc++.h>

using namespace std;

const int N=1005;
const int INF = 1e9+3;
typedef pair<int,int> pii;
vector<pii> grid;
vector<pair<pii,int>> list_of_edge;
int dist[N];
int n,m;


bool bellman_ford_cycle(int s)
{
    for (int i=1; i<n; i++)
    {
        dist[i]=INF;
    }
    dist[s]=0;

    for (int i=1; i<=n; i++)
    {
        for (int u=1; u<=n; u++)
        {
            for (auto d : list_of_edge)
            {
                int u = d.first.first;
                int v = d.first.second;
                int w = d.second;

                if( dist[u]!= INF && dist[v] > dist[u]+w)
                {
                    dist[v]= dist[u]+w;
                }
            }
        }
    }

    for (int i=1; i<n ; i++)
    {
        for (auto d : list_of_edge)
        {
            int u = d.first.first;
            int v = d.first.second;
            int w= d.second;

            if(dist[u] != INF && dist[v]> dist[u]+w)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        list_of_edge.push_back({{u,v},w});
    }

    if (bellman_ford_cycle(1))
    {
        cout<<"YES! Negative cycle detected"<<endl;// 
    }
    else 
    {
        cout<<"NO! No negative cycle detected"<<endl;
    }
    return 0;
}

