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
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v]=1; // directed graph will be only this line 
        adjMatrix[v][u]=1;// undirectes grap will be both line
        

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

