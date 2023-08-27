#include <bits/stdc++.h>

using namespace std;

const int N = 1004;
const int INF = 1e9 + 3;
typedef pair<int, int> pii;
vector<pair<pii, int>> list_of_edge;
int dist[N];
int path[N];
int n, m;

void bellman_ford(int s)
{

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        path[i] = -1;
    }
    dist[s] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto d : list_of_edge)

        {
            int u = d.first.first;
            int v = d.first.second;
            int w = d.second;

            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                path[v] = u;
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
        list_of_edge.push_back({{u, v}, w});
    }

    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "shortest path " << i << " : " << path[i] << endl;
    }

    cout << endl
         << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "shortest distences " << i << " : " << dist[i] << endl;
    }

    return 0;
}
