#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

vector<vector<int>> ans;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    vector<int> cmnts;
    cmnts.push_back(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            cmnts.push_back(v);
        }
    }
    ans.push_back(cmnts);
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

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        bfs(i);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Component " << i +1<< ": ";
        for (int c : ans[i])
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}