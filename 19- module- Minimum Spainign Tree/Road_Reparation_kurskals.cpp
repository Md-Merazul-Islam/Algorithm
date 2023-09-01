#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
const int N = 1e5 + 2;

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
    return (a.w < b.w);
}

int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int Node)
{
    while (parent[Node] != -1)
    {
        Node = parent[Node];
    }
    return Node;
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
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
        dsu_union(a, b);
    }
    long long sum = 0;
    for (Edge val : ans)
    {
        sum += (long long)val.w;
    }

    if(ans.size() == n-1)
    {
        cout<<sum<<endl;
    }
    else 
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}