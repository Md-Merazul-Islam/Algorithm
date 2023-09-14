
class Solution
{
public:
    int longestCommonSubsequence(string tx1, string tx2)
    {
        int n = tx1.size();
        int m = tx2.size();

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (tx1[i - 1] == tx2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
