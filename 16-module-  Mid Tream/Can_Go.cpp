#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 3;
const int INF = 1e9 + 3;
typedef pair<int, int> pii;
vector<pii> adj[N];
vector<int> dist(N, INF);
int visited[N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        pii parent = pq.top();
        pq.pop();

        int PN = parent.second;
        int PC = parent.first;
        if (visited[PN] && dist[PN] < PC)
        {
            continue;
        }

        for (auto child : adj[PN])
        {
            int CN = child.first;
            int CC = child.second;
            if (PC + CC < dist[CN])
            {
                dist[CN] = PC + CC;
                pq.push({dist[CN], CN});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int s;
    cin >> s;
    dijkstra(s);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (dist[a] <= b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
