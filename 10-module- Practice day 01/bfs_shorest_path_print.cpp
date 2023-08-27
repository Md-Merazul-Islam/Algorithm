#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 2;
typedef pair<int, int> pii;
vector<string> grid;
int distances[N][N];
bool visited[N][N];
int n, m;
pii parent[N][N];
vector<pii> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int st_i, int st_j)
{
    queue<pii> q;
    q.push({st_i, st_j});
    distances[st_i][st_j] = 0;
    visited[st_i][st_j] = true;

    while (!q.empty())
    {
        pii curNode = q.front();
        q.pop();

        int row = curNode.first;
        int col = curNode.second;

        for (auto di : direction)
        {
            int new_row = row + di.first;
            int new_col = col + di.second;

            if (isvalid(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] != 'x')
            {
                q.push({new_row, new_col});
                visited[new_row][new_col] = true;
                distances[new_row][new_col] = distances[row][col] + 1;
                parent[new_row][new_col] = {row, col};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int st_i, st_j, ed_i, ed_j;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
            {
                st_i = i, st_j = j;
            }
            if (x[j] == 'e')
            {
                ed_i = i, ed_j = j;
            }
        }
        grid.push_back(x);
    }

    bfs(st_i, st_j);

    if (distances[ed_i][ed_j] != 0)

    {
        // cout << "YES" << endl;
        cout << distances[ed_i][ed_j] << endl;
    }
    else
    {
        // cout << "NO" << endl;
        cout << "-1" << endl;
        return 0;
    }



// ----------------------------------------------------------->


    vector<pii> path;
    pii cur = {ed_i, ed_j};
    while (!(cur.first == st_i && cur.second == st_j))
    {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    path.push_back({st_i, st_j});
    reverse(path.begin(), path.end());

    for (auto p : path)
    {
        cout << p.first << " " << p.second << endl;
    }

    for (int i = 1; i < path.size(); i++)
    {
        // path[i-1]---> path[i]
        if (path[i - 1].first == path[i].first) // left/ right movment
        {
            if (path[i - 1].second == path[i].second - 1) // right
            {
                cout << "R";
            }
            else
            {
                cout << "L";
            }
        }
        else // up /down movment
            if (path[i - 1].first == path[i].first - 1)// down
            {
                cout << "D";
            }
            else
            {
                cout<<"U";
            }
        {
        }
    }

    return 0;
}



