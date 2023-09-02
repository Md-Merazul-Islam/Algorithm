#include <bits/stdc++.h>

using namespace std;

const int N = 104;
const long long INF = 1e18+5 ;
long long dist[N][N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j) 
            {
                dist[i][j] = 0;
            }
        }
    }
    while (m--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b],w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = min(dist[i][k] + dist[k][j],dist[i][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        long long ans = dist[x][y];

        if (ans == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}



