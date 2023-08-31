#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3;
int parent[N];
int parentRank[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentRank[i] = 0;
    }
}

int dsu_find(int node)
{
    if (parent[node] != node)
    {
        parent[node] = dsu_find(parent[node]);
    }
    return parent[node];
}

void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentRank[leaderA] > parentRank[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentRank[leaderA] < parentRank[leaderB])
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
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    map<int, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        int ledr = dsu_find(i);
        mp[ledr] = true;
    }
    vector<int> v;
    for (const auto& p : mp)
    {
        v.push_back(p.first);
    }
    cout << v.size() - 1 << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " " << v[i + 1] << endl;
    }
    return 0;
}
