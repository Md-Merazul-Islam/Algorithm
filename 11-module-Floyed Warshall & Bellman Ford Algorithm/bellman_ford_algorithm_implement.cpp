// O(nm)
//O(n^n)
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int INF = 1e9 + 3;
typedef pair<int, int> pii;
vector<pii> grid[N];
int dis[N];

int n, m;

void bellmen_frod(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (auto d : grid[u])
            {
                int v = d.first;
                int w = d.second;

                if (dis[u] != INF && dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        grid[u].push_back({v,w});
    }
    bellmen_frod(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << " : " << dis[i] << endl;
    }

    return 0;
}