#include <bits/stdc++.h>

using namespace std;
int parent[1000];
int parentSize[1000];
void dsu_set(int n)
{
    for (int i=1 ; i<=n; i++)
    {
        parent[i]=-1;
        parentSize[i]=1;
    }
}

int dsu_find (int node)
{

    while(parent[node] !=-1)
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a,int b)
{
     int leaderA = dsu_find(a);
     int leaderB = dsu_find(b);
     if(leaderA != leaderB )
     {
        parent[leaderB]=leaderA;

     }
}

int main()
{
    int n,m;
    cin>>n>>m;
    dsu_set(n);
    while(m--)
    {
        int a,b;  
        cin>>a>>b;
        dsu_union(a,b);
        
    }
    for (int i=1; i<=n; i++)
    {
       
       cout<<"Parent of "<<i<<" : "<<parent[i]<<endl;
    }
    
    return 0;
}