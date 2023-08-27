#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 5;
typedef pair<int, int> Pair;
vector<Pair> adj[N];
bool visited[N];
int level[N];

vector<int> distances(N, INF);

void bfs(int s) // s= source
{
    priority_queue<queue<Pair>, vector<Pair>, greater<Pair>> pq;
    distances[s] = 0;
    visited[s]=true;
    pq.push({distances[s], s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (Pair v_pair : adj[u])
        {
            int v = v_pair.first;
            int w = v_pair.second;

            if (visited[v])
                continue;
            if (distances[v] > distances[u] + w)
            {
                distances[v] = distances[u] + w;
                pq.push({distances[v], v});
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
    int s, d;
    cin >> s >> d;
    bfs(s);
    cout<<distances[d]<<endl;
    return 0;
}