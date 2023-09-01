//O(v+eloge)
//O(eloge)

#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 3;
vector<pi> v[N];
bool vist[N];

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    vector<Edge> edgelist;
    pq.push({Edge(s, s, 0)});
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if (vist[b])
            continue;
        vist[b] = true;
        edgelist.push_back(parent);
        for (auto child : v[b])
        {
            if (child.first)
            {
                pq.push(Edge(b, child.first, child.second));
            }
        }
    }
    edgelist.erase(edgelist.begin());
    for (Edge val : edgelist)
    {
        cout << val.a << " " << val.b << " " << val.w << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    prims(1);

    return 0;
}