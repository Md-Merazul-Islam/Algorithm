#include <bits/stdc++.h>

using namespace std;
const int N = 106;
typedef pair<int, int> pii;
int level[N][N];
bool visited[N][N];
vector<pii> direction = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool isValid(int n, int m, int ki, int kj)
{
    return (ki >= 0 && ki < n && kj >= 0 && kj < m);
}

void bfs(int n, int m, int ki, int kj)
{
    queue<pii>pq;
    visited[ki][kj] = true;
    pq.push({ki, kj});
    level[ki][kj] = 0;
    while (!pq.empty())
    {
        pii parent = pq.front();
        pq.pop();

        int pi = parent.first;
        int pj = parent.second;

        for (auto child : direction)
        {
            int ni = pi + child.first;
            int nj = pj + child.second;

            if (isValid(n, m, ni, nj) && !visited[ni][nj])
            {
                visited[ni][nj] = true;
                pq.push({ni, nj});
                level[ni][nj] = level[pi][pj] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                level[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
            }
        }
        bfs(n, m, ki, kj);

        if (ki == qi && kj == qj)
        {
            cout << 0 << endl;
        }
        else
        {
            if (level[qi][qj])
            {
                cout << level[qi][qj] << endl;
            }

            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
