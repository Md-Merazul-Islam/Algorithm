// #include <bits/stdc++.h>

// using namespace std;

// const int N= 1e5+1;
// vector<int> garph[N];
// vector<bool> visited(N,false);

// void dfs(int u)
// {
//     visited[u]=true;
//     for (int v : garph[u])
//     {
//         if(visited[v]) continue;
//         dfs(v);
//     }
// }

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     for (int i=0; i<m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         garph[u].push_back(v);
//         garph[v].push_back(u);
//     }

//     vector<int>ld;
//     for (int i=1; i<=n; i++)
//     {
//         if(visited[i])continue;
//         ld.push_back(i);
//         dfs(i);
//     }

//     cout<<"total need path :"<<ld.size()-1<<endl;

//     for (int i=1; i<ld.size(); i++)
//     {
//         cout<<ld[i-1]<<" "<<ld[i]<<endl;

//     }

// return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e3 + 5;
// vector<int> g[N];
// bool visited[N];
// vector<int> parent(N, -1);
// vector<int> distances(N, 0);

// void bfs(int s)
// {
//     queue<int> q;
//     q.push(s);
//     visited[s] = true;

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

//     cout << distances[n] << endl;

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
int n,m;
const int N=1e3+5;
vector<string> str;
bool visited[N][N];

bool isvalid(int i, int j)
{
    return (i>0 && i<n && j>0 && j<m);
}
void dfs(int i, int j)
{
    if(!isvalid(i,j) || visited[i][j] || str[i][j]=='#') return;

    visited[i][j]=true;
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
    
}
int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        str.push_back(x);
    }
    int cnt =0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if(visited[i][j] || str[i][j]== '#') continue;
            dfs(i,j);

            cnt++;
        }
    }

    cout<<cnt ;
    return 0;
}