#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{

    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
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
            parentSize[leaderB]+= parentSize[leaderA]; 
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
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    for (int i = 1; i <= 8; i++)
    {
        cout<<parentSize[i];
        cout << endl;
    }

    return 0;
}