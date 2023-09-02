#include <bits/stdc++.h>

using namespace std;
const int N = 1000009;

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int parent[N];
int parentRank[N];
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentRank[i] = 0;
    }
}

void dsu_rank(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentRank[leaderA] > parentRank[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentRank[leaderA] > parentRank[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentRank[leaderA]++;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    dsu_set(n);
    vector<Edge> v;
    vector<Edge> ans;
    while (m--)

    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({a, b, w});
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_rank(a, b);
    }
    int sum = 0;
    for (Edge val : ans)
    {
        sum += val.w;
    }
    cout << sum << endl;
    return 0;
}