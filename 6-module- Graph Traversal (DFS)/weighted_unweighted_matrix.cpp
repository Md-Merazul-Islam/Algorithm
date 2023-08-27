#include <bits/stdc++.h>
using namespace std;
const  int N= 1e3+5;
int adjMatrix[N][N];
int main()
{
    int n,m; // here n is Node number 
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adjMatrix[u][v]=w; // directed graph will be only this line 
        adjMatrix[v][u]=w;// undirectes grap will be both line
        

    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            // checck adjcency matrix er index gula 
            cout <<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

