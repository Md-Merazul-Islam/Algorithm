#include <bits/stdc++.h>

using namespace std;
const long long INF = 1e18 + 2;
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
        int a, b;
        long long w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    int s;
    cin >> s;
    int t;
    cin >> t;

     vector<long long> dist(n + 1, INF);
        dist[s] = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            for (auto ed : v)
            {
                int u = ed.u;
                int v = ed.v;
                long long w = ed.w;
                if ( dist [u] != INF && dist[u] + w < dist[v])
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
            long long w = ed.w;
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                cycle = true;
                break;
            }
        }

    while (t--)
    { 
        int d;
        cin >> d;

        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else if (dist[d] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[d] << endl;
        }
    }

    return 0;
}
