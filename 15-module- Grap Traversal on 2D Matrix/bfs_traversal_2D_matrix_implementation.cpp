#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

const int N=1e3+3;
bool visited[N][N];
int dist[N][N];
vector<pi> direct={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;

bool isValid(int ci, int cj)
{
    return (ci>=0 && ci<n && cj>=0 && cj<m);
}
void bfs(int si,int sj)
{
    queue<pi>q;
    q.push({si,sj});
    dist[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty())

    {
        pi parent = q.front();
        q.pop();

        int pI = parent.first;
        int pJ= parent.second;

        for (auto d : direct)
        {
            int ci = pI + d.first;
            int cj = pJ + d.second;
            if(isValid(ci,cj) && !visited[ci][cj] )
            {
                visited[ci][cj]=true;
                q.push({ci,cj});
                dist[ci][cj]=dist[pI][pJ]+1;
            }
        }
    }
}

int main()
{

    cin>>n>>m;
    char a[n][m];
    for (int i=0; i<n;i++) 
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
     for (int i=0; i<n;i++) 
    {
        for(int j=0; j<m; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}