#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adj[N][N]; // make a 2D matrix

vector<int> ans[N]; // make a vector for in stock data

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> adj[i][j]; // insert data in 2d matrix
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] == 1)
            {
                ans[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "List" << i << " : ";
        for (int j  : ans[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}