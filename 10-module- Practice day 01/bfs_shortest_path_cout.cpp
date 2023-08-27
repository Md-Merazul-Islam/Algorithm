#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e3 + 5;
typedef pair<int, int> Pair;
vector<string> grid;
int distances[N][N];
bool visited[N][N];

vector<Pair> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};


bool isvalid(int row, int col)
{
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void bfs(int st_i, int st_j)
{

    queue<Pair> pq;
    pq.push({st_i, st_j});
    visited[st_i][st_j] = true;
    distances[st_i][st_j] = 0;

    while (!pq.empty())
    {

        Pair curNode = pq.front();
        pq.pop();

        int row = curNode.first;  // i=row
        int col = curNode.second; // j=col

        for (auto di : direction)
        {
            int new_Row = row + di.first;  
            int new_Col = col + di.second; 

            if (isvalid(new_Row, new_Col) && !visited[new_Row][new_Col] && grid[new_Row][new_Col] != 'x')
            {
                pq.push({new_Row, new_Col});
                visited[new_Row][new_Col] = true;
                distances[new_Row][new_Col] = distances[row][col] + 1;
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

                st_i = i;
                st_j = j;
            }
            if (x[j] == 'e')
            {

                ed_i = i;
                ed_j = j;
            }
        }
        grid.push_back(x);
    }

    bfs(st_i, st_j);


    if (distances[ed_i][ed_j] != 0)
    {

        cout << distances[ed_i][ed_j] << endl;
    }
    else
        cout << "-1" << endl;

    return 0;
}
