#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 4;
vector<string> g;
bool visited[N][N];
typedef pair<int, int> Pair;
vector<Pair> direct = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m;
int level[N][N];
Pair parent[N][N];
bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<Pair> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        Pair u_pair = q.front();
        q.pop();
        int i = u_pair.first;
        int j = u_pair.second;

        for (auto d : direct)
        {
            int ni = i + d.first;
            int nj = j + d.second;
            if (isvalid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        // g.push_back(x);
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 'A')
                si = i, sj = j;

            if (x[j] == 'B')
                di = i, dj = j;
        }
        g.push_back(x);
    }
    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << "YES" << endl;
        cout << level[di][dj] << endl;
    }
    else
    {

        cout << "NO" << endl;
        return 0;
    }

    vector<Pair> path;
    Pair cur = {di, dj};
    while (!(cur.first == si && cur.second == sj))
    {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }

    path.push_back({si, sj});

    reverse(path.begin(), path.end());

    for (int i = 1; i < path.size(); i++)
    {
        if (path[i - 1].first == path[i].first) // jar thek astechi tara 2 jon same row te
        {
            if (path[i - 1].second == path[i].second - 1)
            {
                cout << "R";
            }
            else
            {
                cout << "L";
            }
        }
        else // upore niche
        {
            if (path[i - 1].first == path[i].first - 1)
            {
                cout << "D";
            }
            else
            {
                cout << "U";
            }
        }
    }
    return 0;
}
