
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string a, b;
//     cin >> a >> b;
//     int n = a.size(), m = b.size();
//     int dp[n + 1][m + 1];
//     memset(dp, 0, sizeof(dp));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (a[i - 1] == b[j - 1])
//             {
//                 dp[i][j] = dp[i - 1][j - 1] + 1;
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//         }
//     }
//     // cout<<dp[n][m];

//     int i = n, j = m;
//     string ans;
//     while (i != 0 && j != 0)
//     {
//         if (a[i - 1] == b[j - 1])
//         {
//             ans += a[i - 1];
//             i--;
//             j--;
//         }
//         else
//         {
//             if (dp[i][j - 1] > dp[i - 1][j])
//             {
//                 j--;
//             }
//             else
//             {
//                 i--;
//             }
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     cout << ans << endl;
//     return 0;
// }
#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the LCS matrix using dynamic programming
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    int i = m, j = n;
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs = text1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}

int main()
{
    string text1;
    cin >> text1;
    string text2;
    cin >> text2;

    string lcs = longestCommonSubsequence(text1, text2);

    cout << lcs << endl;

    return 0;
}
