#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3;
vector<pair<int, int>> adjMtx[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // when will be weighte
        adjMtx[u].push_back({v, w}); //make_pair(v,w)
        // adjMtx[v].push_back({u, w}); //make_pair(v,w)
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (auto j : adjMtx[i])
        {
            cout << "("<<j.first << " ,";
            cout << j.second << " )";
        }
        cout << endl;
    }
    return 0;
}