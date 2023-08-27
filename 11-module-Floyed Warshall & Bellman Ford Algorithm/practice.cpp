#include <bits/stdc++.h>
using namespace std;

const int N = 1004;
const int INF = 1e9 + 3;
int d[N][N];
int n, m;

void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void pirntAns()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "X ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                d[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    floyd_warshall();
    pirntAns();

    return 0;
}