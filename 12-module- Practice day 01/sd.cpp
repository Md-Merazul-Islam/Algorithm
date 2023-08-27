#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>>& image, int i, int j, int color , int tra)
    {
        int n = image.size();
        int m = image[0].size();
        if( i<0 || i>=n || j<0 || j>=m  || image[i][j]!= tra)
        {
            return ;
        }

        image[i][j]= color;
        for(auto p : dir)
        {
            dfs(image,i+p.first,j+p.second,color,tra);
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] == color)
        {
            return image;
        }

        int target_color = image[sr][sc];
        
        dfs(image,sr,sc,color,target_color);
        return image;

    }

};