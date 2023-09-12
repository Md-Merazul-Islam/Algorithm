#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 4;
int dp[N];
bool makeit(int s, long long n)
{
    if (s == n)
        return true;
    if (s > n)
        return false;
    if (dp[s] != -1)
        return false;
    
    bool ans = makeit(s + 3, n) || makeit(s * 2, n);
    dp[s] = ans;
    return dp[s];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            dp[i] = -1;
        }
        // dp[1] = true;
        
        if (makeit(1, n))
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