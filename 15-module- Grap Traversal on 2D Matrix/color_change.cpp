#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int N =100;
    bool visited[100][100];
    int n,m;
    vector<pair<int,int>> direction={{0,1},{0,-1},{1,0},{-1,0}};

    bool isValid(int i, int j)
    {
        return (i>=0 && i<n && j>=0 && j<m );
    }

    void dfs(int i, int j,int s_color, int chng_color,vector<vector<int>>& image)
    {
        visited[i][j]= true;
        if(image[i][j]==s_color)
        {
            image[i][j]=chng_color;
        }
        for (auto d : direction)
        {
            int ni = i+ d.first;
            int nj = j+ d.second;
            if ( isValid(ni,nj) && !visited[ni][nj] && image[ni][nj] == s_color)
            {
                dfs(ni ,nj, s_color,chng_color, image);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        n = image.size();
        m = image[0].size();
        dfs(sr,sc,image[sr][sc],color,image);
        return image;

    }
};