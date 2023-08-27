#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
typedef pair<int,int> Pii;
vector<string> grid;
int dist[N][N];
bool visitrd[N][N];
int n,m;
vector <Pii> direction= {{0,1},{0,-1},{1,0},{-1,0}};

bool isValid(int row, int col)
{
    return(row>=0 && row <n && col>=0 && col<m);
}

void dfs(int R, int C)//R = st_i,  C = st_j;
     
{
    visitrd[R][C]=true;
    dist[R][C]= -1;

    
    for (auto d : direction)
    {
        int newR= R+d.first;
        int newC = C+d.second;
        if(isValid(newR,newC) && grid[newR][newC]!='x' && !visitrd[newR][newC] )
        {
            visitrd[newR][newC]=true;
            dist[newR][newC]= dist[R][C]+1;
            dfs(newR,newC);

        } 
    }
}

int main()
{
    cin>>n>>m;
    int st_i, st_j,ed_i,ed_j; // st= source , ed= destination
    for (int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        grid.push_back(x);
        for (int j=0; j<m; j++)
        {
            if(x[j]=='s')
            {
                st_i=i, st_j=j;
            }
            if(x[j]=='e')
            {
                ed_i=i,ed_j=j;
            }
        }
    }

    dfs(st_i,st_j);

    if(dist[ed_i][ed_j]!=0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }


    
    return 0;
}