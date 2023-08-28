#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 4;
int main()
{
    int n, m;
    cin >> n >> m;
    int dist[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
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
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "X ";
            }
            else
            {

                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    cout << " after " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "X ";
            }
            else
            {

                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}