#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1005;
typedef pair<int, int> Pair;
int level[N][N]; 
bool visited[N][N];
// is vector is use for possible movment (up, down, left, right)
vector<Pair> direct = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<string> grid;

bool isvalid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int st_i, int st_j)
{
    queue<Pair> pq;
    pq.push({st_i, st_j});
    level[st_i][st_j] = 0;
    visited[st_i][st_j] = true;

    while (!pq.empty())
    {
        Pair current_cell = pq.front();
        pq.pop();
        int row = current_cell.first;
        int col = current_cell.second;

        for (auto direction : direct)
        {
            int new_row = row + direction.first;
            int new_col = col + direction.second;

            if (isvalid(new_row, new_col) && !visited[new_row][new_col] && grid[new_row][new_col] != 'x')
            {
                pq.push({new_row, new_col});
                visited[new_row][new_col] = true;
                level[new_row][new_col] = level[row][col] + 1;
                
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int start_i, start_j, end_i, end_j;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            if (s[j] == 's')
            {
                start_i = i, start_j = j;
            }
            if (s[j] == 'e')
            {
                end_i = i, end_j = j;
            }
        }
        grid.push_back(s);
    }

    bfs(start_i, start_j);
    
    if (level[end_i][end_j])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;

    }
   
    return 0;
}
