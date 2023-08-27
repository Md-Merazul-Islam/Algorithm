// #include <bits/stdc++.h>

// using namespace std;
// const int N = 1e3 + 5;
// vector<string> g;
// bool visited[N][N];
// int n, m;
// bool isValid(int i, int j) // sarir maje ache kina ta check
// {
//     return (i > 0 && i < n && j > 0 && j < m);
// }

// void dfs(int i, int j)
// {

//     if (!isValid(i, j) || visited[i][j] || g[i][j]=='#') // deyal er bhitore kina || already visited kina || block ba deyal ache kina
//     return;

//     visited[i][j] = true;// er por noton room e dokle thake visited korte hobe
//     dfs(i, j + 1);
//     dfs(i, j - 1);
//     dfs(i + 1, j);
//     dfs(i - 1, j);
// }

// int main()
// {

//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         string x;
//         cin >> x;
//         g.push_back(x);
//     }
//     int cnt = 0;// room count korar jonno /cc
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (visited[i][j] || g[i][j] == '#') // check visited or blocked deyal
//                 continue;

//             dfs(i, j);
//             cnt++;
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e3 + 5;
vector<string> str;
bool visited[N][N];
typedef pair<int, int> PAIR;
vector < PAIR > direc= {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isvalid(int i, int j)
{
    return (i > 0 && i < n && j > 0 && j < m);
}
void dfs(int i, int j)
{
    if (!isvalid(i, j) || visited[i][j] || str[i][j] == '#')
        return;

    visited[i][j] = true;
    for (auto d : direc)
    {
        dfs(i+d.first, j+d.second);

    } 
    // dfs(i, j + 1);
    // dfs(i, j - 1);
    // dfs(i + 1, j);
    // dfs(i - 1, j);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        str.push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] || str[i][j] == '#')
                continue;
            dfs(i, j);

            cnt++;
        }
    }

    cout << cnt;
    return 0;
}