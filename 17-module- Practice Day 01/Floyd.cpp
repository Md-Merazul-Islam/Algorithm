#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int INF = 105;
    int dist[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
            if(dist[i][j]==-1)
            {
                dist[i][j]=INF;
            }
        }
    }
    
    int mx = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }

                
            if (dist[i][j] != INF && dist[i][j]>mx)
            {
                 mx =dist[i][j] ;
            }
            }
        }
    }

    cout << mx << endl;

    return 0;
}