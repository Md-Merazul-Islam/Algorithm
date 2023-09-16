#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 2;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - m;
        vector<int> dp(s+1, INF);
        dp[0] = 0;
        for (int i = 1; i <= s; i++)
        {
            for (int val : a)
            {
                if (val <= i)
                {
                    dp[i] = min(dp[i], dp[i - val] + 1);
                }
            }
        }
        if (dp[s] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[s] << endl;
        }
    }
    return 0;
}

// ----------------------------> used  <<<<2D DP>>>
#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9 + 3;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int s = 1000 - m;
        vector<vector<int>> dp(n + 1, vector<int>(s + 1, INF));

        for (int j = 1; j <= s; j++)
        {
            dp[0][j] = INF;
        }

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = min(dp[i][j - a[i - 1]] + 1, dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][s] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[n][s] << endl;
        }
    }
    return 0;
}
