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
    vector<Edge> v;

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : v)
        {
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;
            if(dist[u]+w < dist[v])
            {
                dist[v]= dist[u]+w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << " : " << dist[i]<<endl;
    }

    return 0;
}