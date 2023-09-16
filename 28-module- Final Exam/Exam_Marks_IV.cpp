#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
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
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (int i : a)
        {
            for (int j = i; j <= s; j++)
            {
                if (i <= j)
                {

                    dp[j] = dp[j] + dp[j - i];

                    if (dp[j] > mod)
                    {
                        dp[j] %= mod;
                    }
                }
            }
        }

        cout << dp[s] << endl;
    }
    return 0;
}

// dp te store koray time a check korben, j value ta 1e9+7 er theke boro kina
// jodi boro hoy tahole value ta 1e9+7 diye mod kore store krbn, jodi choto hoy tahole direct store korben