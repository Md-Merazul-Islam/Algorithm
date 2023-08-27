#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+4;
const int INF = 1e9+3;
typedef pair<int,int>pai;
vector<pai> adj[N];
vector<int>dist(N,INF);
bool visited[N];

void dijkstra(int s)
{
    queue<int>q;
    dist[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (pai child : adj[parent])
        {
            int childNode = child.first;
            int childCost = child.second;
            if(dist[parent] + childCost < dist[childNode])
            {
                dist[childNode]= dist[parent]+childCost;
                q.push(childNode);
            }
        }

    }
}

int main()
{    
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        
    }

    dijkstra(1);
    for (int i=1; i<=n;i++)
    {
        cout<<"Distances of "<<i<<": ";
        cout<<dist[i]<<endl;
    }
    return 0;
}


