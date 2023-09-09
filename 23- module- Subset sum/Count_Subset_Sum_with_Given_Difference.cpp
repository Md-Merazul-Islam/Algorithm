#include <bits/stdc++.h>

using namespace std;
int cntdif(int n, int a[], int target)
{
    int total_sum = 0;
    for (int i = 0; i < n; i++)
    {
        total_sum += a[i];
    }
    int s = (total_sum + target) / 2;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int target;
    cin >> target;

    int count = cntdif(n, a, target);
    cout << count << endl;
    return 0;
}