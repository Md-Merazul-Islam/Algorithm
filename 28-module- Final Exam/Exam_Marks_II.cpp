#include <bits/stdc++.h>

using namespace std;

bool exam_mark(int n, int m, int a[])
{
    int s= 1000-m;
    bool dp[n + 1][s + 1];
    for (int i = 0; i <= s; i++)
    {
        dp[0][i] = false;
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - a[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}

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
        if (exam_mark(n, m, a))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}