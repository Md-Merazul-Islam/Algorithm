#include <bits/stdc++.h>

using namespace std;
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
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    vector<Edge> v;
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

    bool cycle = false;
    for (auto ed : v)
    {
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;
        if (dist[u] + w < dist[v])
        {
            cycle = true;
            break;
            dist[v] = dist[u] + w;
        }
    }

    if (cycle)
    {
        cout << "Cylcle exist" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }
    return 0;
}