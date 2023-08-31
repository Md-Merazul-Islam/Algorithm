#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentRank[1000]; 

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

void dsu_union(int a, int    b)
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
    int n, m;
    cin >> n >> m;
    dsu_set(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Parent of " << i << " : " << dsu_find(i) << endl;
    }

    return 0;
}
