#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3l;
const int INF = 1e9 + 4;
typedef pair<int, int> pai;
vector<int> adj[N];
vector<int> dist(N, INF);
bool visited[N];
int part[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    visited[s] = true;
    part[s] = -1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                part[child] = parent;
                dist[child] = dist[parent] + 1;
                visited[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Parent of " << i << ": ";
        cout << part[i] << endl;
    }

    int d;
    cin >> d;
    vector<int> v;
    if (visited[d])
    {
        int x = d;
        while (x != -1)
        {
            v.push_back(x);
            x = part[x];
        }

        reverse(v.begin(), v.end());
        for (int path : v)
        {
            cout << path << " ";
        }
    }

    else
    {
        cout << "path not found " << endl;
    }
    return 0;
}

