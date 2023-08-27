#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
vector<vector<int>> components;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> component;
    component.push_back(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                component.push_back(v);
            }
        }
    }

    components.push_back(component);
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

    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }

    cout << "Connected Components:" << endl;
    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";
        for (int node : components[i])
        {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
