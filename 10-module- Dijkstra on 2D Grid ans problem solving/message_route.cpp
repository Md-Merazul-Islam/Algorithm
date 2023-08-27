
// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e3 + 5;
// const int INF = 1e9 + 7;
// vector<int> g[N];
// bool visited[N];
// vector<int> parent(N, -1);
// // vector<int> distances(N);
// vector<int> distances(N, INF);
// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;
//     distances[s]=0;

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v : g[u])
//         {
//             if (visited[v])
//                 continue;
//             q.push(v);
//             visited[v] = true;
//             parent[v] = u;
//             distances[v] = distances[u] + 1;
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     bfs(1);

//     cout << distances[n] << endl; // for distance

//     vector<int> path;
//     int cur = n;
//     while (cur != -1)
//     {
//         path.push_back(cur);
//         cur = parent[cur];
//     }

//     reverse(path.begin(), path.end());
//     for (int p : path)
//     {
//         cout << p << " ";
//     }

//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int INF = 1e9 + 7; // Infinity
vector<int> g[N];
bool visited[N];
vector<int> parent(N, -1);
vector<int> distances(N, INF); // Initialize distances with INF

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    distances[s] = 1; // Update distance for source vertex

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            distances[v] = distances[u] + 1; // Update distance for vertex v
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);

    if (parent[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {

        vector<int> path;
        int cur = n;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parent[cur];
        }

        reverse(path.begin(), path.end());
        cout << distances[n] << endl;
        for (int p : path)
        {
            cout << p << " ";
        }
    }
    return 0;
}
