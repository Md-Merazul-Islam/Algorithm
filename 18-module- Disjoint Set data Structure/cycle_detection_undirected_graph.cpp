
#include <bits/stdc++.h>
using namespace std;

int parent[1000];
int parentRank[1000];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentRank[i] = 0; // Initialize parentRank as 0
    }
}

int dsu_find(int node)
{
    if (parent[node] != node)
    {
        parent[node] = dsu_find(parent[node]); // Path compression
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
            parentRank[leaderA]++; // Increment parentRank of the new leader
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
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA== leaderB)
        {
            cout<<"Negative cycle detected between ("<<a<<","<<b<<")"<<endl;
        }
        else
        { 
            dsu_union(a,b);
        }
    }



    return 0;
}
