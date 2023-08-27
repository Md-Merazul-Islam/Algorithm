#include <bits/stdc++.h>

using namespace std;
const int N = 1003;
typedef pair<int, int> pii;
bool visited[N][N];
int dist[N][N];
char a[N][N];
vector<pii> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
int cnt = 0;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (auto d : direction)
    {
        int ni = si + d.first;
        int nj = sj + d.second;
        if (isvalid(ni, nj) && !visited[ni][nj] && a[ni][nj] == '.')
        {
            dfs(ni, nj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                cnt = 0;
                dfs(i, j);
                mn = min(mn, cnt);
            }
          
        }
    }
    if(mn==INT_MAX)
    {
        cout<<-1;
    }
    else 
    {
        cout<<mn<<endl;
    }

    return 0;
}