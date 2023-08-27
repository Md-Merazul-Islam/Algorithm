// #include <bits/stdc++.h>

// using namespace std;
// const int N = 1e3 + 3;
// const int INF = 1e9 + 3;
// typedef pair<int, int> pii;
// vector<pii> adj[N];
// vector<int> dist(N, INF);
// int visited[N];

// void dijkstra(int s)
// {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     dist[s] = 0;
//     pq.push({0, s});

//     while (!pq.empty())
//     {
//         pii parent = pq.top();
//         pq.pop();

//         int PN = parent.second;
//         int PC = parent.first;
//         if (visited[PN] && dist[PN] < PC)
//         {
//             continue;
//         }

//         for (auto child : adj[PN])
//         {
//             int CN = child.first;
//             int CC = child.second;
//             if (PC + CC < dist[CN])
//             {
//                 dist[CN] = PC + CC;
//                 pq.push({dist[CN], CN});
//             }
//         }
//     }
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     while (m--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     }
//     int s;
//     cin >> s;
//     dijkstra(s);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a, b;
//         cin >> a >> b;

//         if (dist[a] <= b)
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(vector<vector<pii>>& graph, int source, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr_node]) {
            continue;
        }

        for (const pii& edge : graph[curr_node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            int new_dist = curr_dist + weight;
            if (new_dist < dist[neighbor]) {
                dist[neighbor] = new_dist;
                pq.push(make_pair(new_dist, neighbor));
            }
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<pii>> graph(N);

    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        graph[A - 1].emplace_back(B - 1, W);
    }

    int S;
    cin >> S;

    int T;
    cin >> T;

    vector<int> dist_from_source(N, INT_MAX);
    dijkstra(graph, S - 1, dist_from_source);

    for (int i = 0; i < T; ++i) {
        int D, DW;
        cin >> D >> DW;
        if (dist_from_source[D - 1] <= DW) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
