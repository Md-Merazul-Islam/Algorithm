#include <bits/stdc++.h>
using namespace std;
bool knapsack(int n, int x, int a[],int sum, int idx)
{

    if (idx == n)
        return sum == x;

    if (knapsack(n, x, a, sum + a[idx], idx + 1))
    {
        return true;
    }
    if (knapsack(n, x, a, sum - a[idx], idx + 1))
    {
        return true;
    }
    return false;
}
int main()
{
    //cout << "Enter Your value:";
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (knapsack(n, x, a,a[0],1))
    {

        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
