// #include <bits/stdc++.h>

// using namespace std;
// const int N = 1005;
// vector<int> adj[N];
// bool visited[N];
//   vector<int> result;

// void dfs(int u, int &count)
// {
//     visited[u] = true;
//     count++;
//     for (int v : adj[u])
//     {
//         if (visited[v])
//             continue;
//         dfs(v, count);
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
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
  
//     for (int i = 0; i < N; i++)
//     {
//         if (visited[i])
//             continue;
//         int count = 0;
//         dfs(i, count);

//         if (count > 1)
//         {
//             result.push_back(count);
//         }
//     }
//     sort(result.begin(), result.end());

//     for (int s : result)
//     {

//         cout << s << " ";
//     }

//     return 0;
// }









// ------------------------>

#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
vector<int> cs;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int cnt = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt++;

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    if (cnt > 1)
        cs.push_back(cnt);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i]== true) continue; 
        
            bfs(i);
        
    }

    sort(cs.begin(), cs.end());
    for (int s : cs)
    {
        cout << s << " ";
    }
    return 0;
}

