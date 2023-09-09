#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int s, int w[], int v[])
{
    if (s == 0 || n == 0)
        return 0;
    if (w[n - 1] <= s)
    {
        return max(knapsack(n - 1, s - w[n - 1], w, v) + v[n - 1], knapsack(n - 1, s, w, v));
    }
    else
    {
        return knapsack(n - 1, s, w, v);
    }
}
int main()
{
    int n, s;
    cin >> n >> s;
    int w[n], v[n];
    for (int i = 0; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }

    cout << knapsack(n, s, w, v) << endl;
    return 0;
}
