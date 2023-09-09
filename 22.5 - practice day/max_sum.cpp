#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N][N];
int dp[N][N];
int mx(int n, int m, int i, int j)
{
    if(i==n || j==m )
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(i<n-1)
    {
        int op1 = mx(n,m,i+1,j);

    }
    if(j<m-1)
    {

        int op2 = mx(n,m,i,j+1);
    }

    return dp[i][j]= a[i][j] + max(op1,op2);
}

int main()
{
    int n,m; cin>>n>>m;

    for (int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j]=-1;
            cin>>a[i][j];
        }
    }



    cout<<mx(n,m,0,0)<<endl;
    return 0;
}
