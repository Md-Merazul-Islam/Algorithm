
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int knapSack(int n, int s, int v[], int w[])
    {

        int dp[s + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (w[i - 1] <= j)
                {
                    dp[j] = max(dp[j - w[i - 1]] + v[i - 1], dp[j]);
                }
                
            }
        }
        return dp[s];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, W;
        cin >> N >> W;
        int val[N], wt[N];
        for (int i = 0; i < N; i++)
            cin >> val[i];
        for (int i = 0; i < N; i++)
            cin >> wt[i];

        Solution ob;
        cout << ob.knapSack(N, W, val, wt) << endl;
    }
    return 0;
}
