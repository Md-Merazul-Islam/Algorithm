#include <bits/stdc++.h>

using namespace std;
int dp[1003][1005];
int LCS(string a, int n, string b, int m)
{

    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (a[n - 1] == b[m - 1])
    {
        return dp[n][m] = LCS(a, n - 1, b, m - 1) + 1;
    }
    else
    {
        int ans1 = LCS(a, n - 1, b, m);
        int ans2 = LCS(a, n, b, m - 1);
        return dp[n][m] = max(ans1, ans2);
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    memset(dp, -1, sizeof(dp));
    cout << LCS(a, n, b, m);

    return 0;
}