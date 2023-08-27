#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 2;
typedef pair<int, int> Pair;
vector<Pair> adj[N];
vector<int> dist(N, INF);
bool visited[N];

void dijkstra(int source)
{
    priority_queue<queue<Pair>, vector<Pair>, greater<Pair>> pq;

    dist[source] = 0;
    pq.push({dist[source], source}); //{distance , node}
    while(!pq.empty())
    {
        int u = pq.top().second; // node 
       pq.pop();
       visited[u]= true;
       for ( Pair v_pair : adj[u] )
       {
            int v = v_pair.first;// node 
            int w= v_pair.second;//weight

            if(visited[v])continue;
    
            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
       }
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1);
    for (int i=1; i<=n; i++)
    {
        cout<<" Distance of node "<<i<<": ";
        cout<<dist[i]<<endl;
    }

    return 0;
}