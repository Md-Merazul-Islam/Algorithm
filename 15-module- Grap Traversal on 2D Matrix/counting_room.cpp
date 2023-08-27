#include <bits/stdc++.h>

using namespace std;

const int N=1003;
int n,m;
bool visited[N][N]; 
char a[N][N];
vector<pair<int,int>> path = {{0,1},{0,-1},{1,0},{-1,0}};
bool isVaild(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<m && a[i][j]=='.');
}
void dfs(int i,int j)
{
    visited[i][j]=true;
    for (auto d : path)
    {
        int ni = i+ d.first;
        int nj = j + d.second;
        if(isVaild(ni,nj) && !visited[ni][nj] && a[ni][nj]!='#')
        {
            dfs(ni,nj);
        }
    }
}
int main()
{
    cin>>n>>m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<m;j++)
        {
            if(!visited[i][j] && a[i][j]=='.')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
    return 0;
}