// #include <bits/stdc++.h>

// using namespace std;

// const int INF = 1e9 + 2;
// const int N = 1e5 + 3;
// typedef pair<int, int> Pair;
// vector<Pair> adj[N];
// bool visited[N];
// vector<int> dist(N, INF);

// void dijktra(int source)
// {
//     priority_queue < queue<Pair>, vector<Pair>, greater<Pair>> pq;
//     dist[source]=0;
//     pq.push({dist[source],source});

//     while(!pq.empty())
//     {
//         int u = pq.top().second;
//             pq.pop();
//             visited[u]=true;
//             for (Pair V_pair : adj[u])
//             {
//                 int v = V_pair.first;
//                 int w= V_pair.second;

//                 if(visited[v]) continue;

//                 if(dist[v] > dist[u]+w)
//                 {
//                     dist[v]= dist[u]+w;
//                     pq.push({dist[v],v});
//                 }

//             }

//     }
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }

//     dijktra(1);

//     for (int i=1; i<=n; i++)
//     {
//         cout<<"Disitance of Node "<<i<<" : ";
//         cout<<dist[i]<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;
// const int N = 1e3 + 2;
// const int INF = 1e9 + 3;
// typedef pair<int, int> Pair;
// vector<Pair> adj[N];
// bool visited[N];
// vector<int> dist(N, INF);

// void dijkstra(int socure)
// {
//     priority_queue<queue<Pair>, vector<Pair>, greater<Pair>> pq;
//     dist[socure] = 0;
//     pq.push({dist[socure], socure});
//     while (!pq.empty())
//     {
//         int u = pq.top().second;
//         pq.pop();
//         visited[u] = true;
//         for (Pair v_pair : adj[u])
//         {
//             int v = v_pair.first;
//             int w = v_pair.second;

//             if (visited[v])
//                 continue;

//             if (dist[v] > dist[u] + w)
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     dijkstra(1);

//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Distance of Node" << i << " : ";
//         cout << dist[i] << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// const int N= 1e3+5;
// vector<int>adj[N];
// bool visited[N];
// int distances[N];

// void bfs(int s)
// {
//     queue<int>q;
//     q.push(s);
//     visited[s]=true;
//     distances[s]=0;

//     while(!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v: adj[u] )
//         {
//             if(visited[v])continue;
//             visited[v]=true;
//             q.push(v);
//             distances[v] = distances[u]+1;
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for (int i=0; i<m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int s,d;
//     cin>>s>>d;
//     bfs(s);

//     for (int i=1; i<=n; i++)
//     {
//         cout<<"Shortest Distance of Node "<<i<<" : ";
//         cout<<distances[i]<<endl;

//     }

//     return 0;

// }

// #include <bits/stdc++.h>

// using namespace std;

// const int N= 1e5+4;
// vector<int> adj[N];
// bool visited[N];
// int parent[N];

// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s]= true;
//     // parent[s]=0;
//     while(!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v : adj[u])

//         {
//             if(visited[v]) continue;
//             visited[v]=true;
//             q.push(v);
//             parent[v]=u;

//         }

//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for (int i=0; i<m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     bfs(1);
//     for (int i=1; i<=n;i++)
//     {
//         cout<<"Parent "<<i<<" : ";
//         cout<<parent[i]<<endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e5 + 4;
// vector<int> adj[N];
// bool visited[N];
// int parent[N];

// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     parent[s]=-1;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v : adj[u])

//         {
//             if (visited[v])
//                 continue;
//             visited[v] = true;
//             parent[v] = u;
//             q.push(v);
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int s, d;
//     cin >> s >> d;
//     bfs(s);
//     int current = d;
//     vector<int> path;
//     while (current != -1)
//     {
//         path.push_back(current);
//         current = parent[current];
//     }

//     reverse(path.begin(), path.end());

//     cout << " path : ";
//     for (int node : path)
//     {
//         cout << node << " ";
//     }

//     return 0;
// }




#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> Pair;
const int N=1e3+4;
const int INF = 1e9+4;
vector<Pair> adj[N];
bool visited[N];
vector<int> distances(N,INF);

void dijkstra(int s)
{
    priority_queue<queue<Pair>, vector<Pair>, greater<Pair>> pq;
    // visited[s]=true;
    distances[s]=0;
    pq.push({distances[s],s});


    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u]=true;
        for (Pair v_p : adj[u])
        {
        
            int v = v_p.first;
            int w = v_p.second;
            if(visited[v]) continue;
            // visited[v]=true;
            if(distances[v]> distances[u]+w)
            {
                distances[v]= distances[u]+w;
                pq.push({distances[v],v});
            }
        }

    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int s;
    cin>>s;
    dijkstra(1);
    for(int i=1; i<=n; i++)
    {
        cout<<"Dijstra distance "<<i<<" : ";
        cout<<distances[i]<<endl;
    }

    return 0;
}