#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
vector<int> adj[N];
bool visited[N];
int distances[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    distances[s] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto p : adj[parent])
        {
            if (!visited[p])
            {
                q.push(p);
                distances[p] = distances[parent] + 1;
                visited[p] = true;
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
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);
    for (int i=1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<": "<<distances[i]<<endl;
    }

    return 0;
}