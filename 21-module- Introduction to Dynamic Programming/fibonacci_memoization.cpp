// O(n)

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 4;

int save[N];
int fibo(int n)
{
    if (n == 1 || n == 0)
        return 1;

    // memoization
    if (save[n] != -1)
    {
        return save[n];
    }

    save[n] = fibo(n - 1) + fibo(n - 2);
    return save[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    cout << fibo(n) << endl;
    return 0;
}
