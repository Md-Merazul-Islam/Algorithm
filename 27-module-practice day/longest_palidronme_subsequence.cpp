
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestPalinSubseq(string a) {
        //code here
        string b= a;
        reverse(b.begin(), b.end());
        int n = a.size();
        int m = b.size();
        
        int dp[n+1][m+1];
        for (int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i==0 || j==0)
                dp[i][j] =0;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        
        return dp[n][m];
        
        
        
        
        
        
        }
};

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
