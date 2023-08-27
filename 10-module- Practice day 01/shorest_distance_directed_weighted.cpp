#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 3;
const int N = 1e3 + 2;
typedef pair<int, int> Pair;
bool visited[N];
vector<Pair> adj[N];
vector<int> distances(N, INF);

void bfs(int s)
{
    priority_queue<queue<Pair>, vector<Pair>, greater<Pair>> pq;

    distances[s] = 0;
    pq.push({distances[s], s});
    // visited[s]= true;

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
    for (int i = 0; i < m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
    int x, y;
    cin >> x >> y;
    bfs(x);
    cout << distances[y] << endl;

    return 0;
}
