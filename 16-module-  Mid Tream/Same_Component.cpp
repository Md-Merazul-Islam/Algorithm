#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int n, m;
char a[N][N];
bool visited[N][N];
int dist[N][N];
typedef pair<int, int> pii;
vector<pii> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{
    queue<pii> q;
    visited[si][sj] = true;
    dist[si][sj] = -1;
    q.push({si, sj});
    while (!q.empty())
    {
        pii parent = q.front();
        q.pop();

        int PI = parent.first;
        int Pj = parent.second;

        for (auto d : direction)
        {
            int ni = PI + d.first;
            int nj = Pj + d.second;
            if (isvalid(ni, nj) && !visited[ni][nj] && a[ni][nj] == '.')
            {
                visited[ni][nj] = true;
                q.push({ni, nj});
                dist[ni][nj] = dist[PI][Pj] + 1;
            }
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
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);

    if (dist[di][dj] )
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}