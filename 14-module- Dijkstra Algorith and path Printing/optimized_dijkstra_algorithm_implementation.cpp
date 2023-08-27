 
// complexity -- O(n+elogn)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const int INF = 1e9 + 3;
typedef pair<int, int> pai;
vector<pai> adj[N];
vector<int> dist(N, INF);
bool visited[N];

void dijkstra(int s)
{
    priority_queue<pai, vector<pai>, greater<pai>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        pai parent = pq.top();
        pq.pop();

        int parent_node = parent.second;
        int parent_cost = parent.first;

        if (visited[parent_node])
        {
            continue;
        }
        visited[parent_node] = true;

        for (auto child : adj[parent_node])
        {
            int child_Node = child.first;
            int child_cost = child.second;
            if (parent_cost + child_cost < dist[child_Node])
            {

                dist[child_Node] = parent_cost + child_cost;
                pq.push({dist[child_Node], child_Node}); // dist[child_node]= cost
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
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << ": ";
        cout << dist[i] << endl;
    }
    return 0;
}