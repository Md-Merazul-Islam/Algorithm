#include <bits/stdc++.h>

using namespace std;
const int INF = 30000;

class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    int dist[n + 1];
    vector<Edge> v;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[1] = 0;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge ed(a, b, c);
        v.push_back(ed);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : v)
        {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    return 0;
}