// O(nm) 
//O(n^n)
#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int INF = 1e9 + 5;
typedef pair<int, int> pii;
vector<pii> grid[N];
vector<pair<pii, int>> list_of_edge;
int dist[N];
int n, m;

void bellmen_ford(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[s] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (auto edge : list_of_edge)
        {
            int u = edge.first.first;  // {u,v} er first
            int v = edge.first.second; //{u,v} er second

            int w = edge.second;

            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        grid[u].push_back({v, w});
        list_of_edge.push_back({{u, v}, w}); // pothome edge pore weight
    }
    bellmen_ford(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << " : " << dist[i] << endl;
    }

    return 0;
}