// #include<bits/stdc++.h>
// using namespace std;
// const int N= 1e5+5;
// vector<int> adjMtx[N];

// int main()
// {
//     int n, m;
//     cin>>n>>m;
//     for (int i=0; i<m; i++)
//     {
//         int u,v;
//         cin>>u>>v;
//         adjMtx[u].push_back(v);// if directed matrix
//         // adjMtx[v].push_back(u);// if undirexted matrix will be both line
//     }

//     for (int i=1; i<=n; i++)
//     {
//         cout<<i<< " : ";
//         for(int j : adjMtx[i])
//         {
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;

// }


#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
vector<int> adj[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0; i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
    {
        cout<<i<<" : ";
        for (int j : adj[i])

        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}