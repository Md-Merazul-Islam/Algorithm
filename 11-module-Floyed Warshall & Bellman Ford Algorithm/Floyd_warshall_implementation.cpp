#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int INF = 1e9 + 3;
int distances[N][N];
int n, m;

void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

void PrintAns()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (distances[i][j] == INF)
            {
                cout << "x ";
            }
            else
            {
                cout << distances[i][j]<<" ";
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
                distances[i][j] = INF;
            }
            
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        distances[u][v] = w;
    }

    floyd_warshall();
    PrintAns();
    return 0;
}